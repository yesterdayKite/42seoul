/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:27:07 by jae               #+#    #+#             */
/*   Updated: 2021/01/27 21:25:44 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				quote_check(t_shell *shell, char **line)
{
	if (quotes(*line, 2147483647))
	{
		ft_putendl_fd("minishell: syntax error with open quotes", STDERR);
		ft_memdel(*line);
		shell->ret = 2;
		shell->start = NULL;
		return (1);
	}
}

char			*space_alloc(char *line)
{
	char		*new;
	int			cnt;
	int			i;

	cnt = 0;
	i = 0;
	while (line[i])
	{
		if (is_sep(line, i))
			cnt++;
		i++;
	}
	if (!(new = malloc(sizeof(char) * (i + 2 * cnt + 1))))
		return (NULL);
	return (new);
}

char			*space_line(char *line)
{
	char		*new;
	int			i;
	int			j;

	i = 0;
	j = 0;
	new = space_alloc(line);
	while (new && line[i])
	{
		if (quotes(line, i) != 2 && line[i] == '$' && i && line[i - 1] != '\\')
			new[j++] = (char)(-line[i++]);
		else if (quotes(line, i) == 0 && is_sep(line, i))
		{
			new[j++] = ' ';
			new[j++] = line[i++];
			if (quotes(line, i) == 0 && line[i] == '>')
				new[j++] = line[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = line[i++];
	}
	new[j] = '\0';
	ft_memdel(line);
	return (new);
}

void			parse(t_shell	*shell)
{
	char		*line;
	t_token		*token;

	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	shell->ret ? ft_putstr_fd("nooo", STDERR) : ft_putstr_fd("gooood", STDERR);
	ft_putstr_fd("\033[0;36m\033[1mminishell ▸ \033[0m", STDERR);
	if (get_next_line(0, &line) == -2 && (shell->exit = 1))
		ft_putendl_fd("exit", STDERR);
	shell->ret = (g_sig.sigint == 1) ? g_sig.exit_status : shell->ret;
	if (quote_check(shell, &line)) // ""과 '' 가 잘 막혀있는지
		return ;
	line = space_line(line); // 명령줄의 space들을 제거한다.
	if (line && line[0] == 'S')
		line[0] = (char)(-line[0]);
	shell->start = get_tokens(line); // token들의 명령어들 중 시작명령어 주소를 start 에 저장한다.
	ft_memdel(line);
	squish_args(shell); // 다음 token으로 너어간다.
	token = shell->start;
	while (token)
	{
		if (is_type(token, ARG))
			type_arg(token, 0);
		token = token->next;
	}
}
