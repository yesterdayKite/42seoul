/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:49:46 by jae               #+#    #+#             */
/*   Updated: 2021/01/27 21:13:17 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**cmd_tab(t_token *start)
{
	t_token		*token;
	char		**tab;
	int			i;

	if (!start)
		return NULL;
	token = start->next;
	i = 2;
	while (token && token->type < TRUNC)
	{
		token = token->next;
		i++;
	}
	if (!(tab = malloc(sizeof(char *) * i)))
		return (NULL);
	token = start->next;
	tab[0] = start->str;
	i = 1;
	while (token && token->type < TRUNC)
	{
		tab[i++] = token->str;
		token = token->next;
	}
	tab[i] = NULL;
	return (tab);
}

void			exec_cmd(t_shell *shell, t_token *token)
{
	char		**cmd;
	int			i;

	if (shell->charge == 0)
		return ;
	cmd = cmd_tab(token);
	i = 0;
	while (cmd && cmd[i])
	{
		cmd[i] = expansions(cmd[i], shell->env, shell->ret); // 단어치고 tab 누르면 해당 단어로 시작하는 명령어 확인
		i++;
	}
	if (cmd && ft_strcmp(cmd[0], "exit") == 0 && has_pipe(token) == 0)
		shell_exit(shell, cmd);
	else if (cmd && is_builtin(cmd[0]))
		shell->ret = exec_builtin(cmd, shell); // 드디어 명령어 실행!
	else if (cmd)
		shell->ret = exec_bin(cmd, shell->env, shell);
	free_tab(cmd);
	ft_close(shell->pipin);
	ft_close(shell->pipout);
	shell->pipin = -1;
	shell->pipout = -1;
	shell->charge = 0;
}
