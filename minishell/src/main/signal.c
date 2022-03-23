/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:43:28 by jae               #+#    #+#             */
/*   Updated: 2021/01/27 21:24:35 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
공부 링크 : https://www.crocus.co.kr/460
signal은 이벤트를 알려주기 위해 쓰이는 메세지.
1. 0으로 나눌때
2. 자식 프로세스가 거질대
3. kill 로 프로세스를 끌 때
4. 한 프로세스에서 시그널 요청할 때  등등등
+) 시그널이보내졌는데, 도착지에서 못받았을때를 Pending 이라고 한다.
*/

void			sig_int(int code)
{
	(void)code;
	if (g_sig.pid == 0)
	{
		ft_putstr_fd("\b\b  ", STDERR);
		ft_putstr_fd("\n", STDERR);
		ft_putstr_fd("\033[0;36m\033[1m🤬 minishexwll ▸ \033[0m", STDERR);
		g_sig.exit_status = 1;
	}
	else
	{
		ft_putstr_fd("\n", STDERR);
		g_sig.exit_status = 130;
	}
	g_sig.sigint = 1;
}

void			sig_quit(int code)
{
	char		*nbr;

	nbr = ft_itoa(code);
	if (g_sig.pid != 0)
	{
		ft_putstr_fd("quit : ", STDERR);
		ft_putendl_fd(nbr, STDERR);
		g_sig.exit_status = 13;
		g_sig.signquit = 1;
	}
	else
		ft_putstr_fd("\b\b  \b\b", STDERR);
	ft_memdel(nbr);
}

void			sig_init(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	g_sig.pid = 0;
	g_sig.exit_status = 0;
}
