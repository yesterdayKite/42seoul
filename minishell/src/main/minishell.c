/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:16:04 by jae               #+#    #+#             */
/*   Updated: 2021/01/28 21:24:46 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig	g_sig;

void	redir_and_exec(t_shell *shell, t_token *token)
{
	t_token		*prev;
	t_token		*next;
	int			pipe;

	prev = prev_sep(token, NOSKIP);
	next = next_sep(token, NOSKIP);
	pipe = 0;
	if (is_type(prev, TRUNC))
		redir(shell, token, TRUNC);
	else if (is_type(prev, APPEND))
		redir(shell, token, APPEND);
	else if (is_type(prev, INPUT))
		input(shell, token);
	else if (is_type(prev, PIPE))
		pipe = minipipe(shell);
	if (next && is_type(next, END) == 0 && pipe != 1)
		redir_and_exec(shell, next->next);
	if ((is_type(prev, END) || is_type(prev, PIPE) || !prev)
		&& pipe != 1 && shell->no_exec == 0)
		exec_cmd(shell, token);
}

void	minishell(t_shell *shell)
{
	t_token		*token;
	int			status;

	token = next_run(shell->start, NOSKIP);
	token = (is_type(shell->start, "TAI")) ? shell->start->next : token;
	while (shell->exit == 0 && token)
	{
		shell->charge = 1;
		shell->parent = 1;
		shell->last = 1;
		redir_and_exec(shell, token);
		reset_std(shell);
		close_fds(shell);
		reset_fds(shell);
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		shell->ret = (shell->last == 0) ? status : shell->ret;
		if (shell->parent == 0)
		{
			free_token(shell->start);
			exit(shell->ret);
		}
		shell->no_exec = 0;
		token = next_run(token, SKIP);
	}
}

int		main(int	ac, char	**av, char	**env)
{
	t_shell		shell;

	(void)ac;
	(void)av;
	shell.in = dup(STDIN); // 파일 서술자를 복제하여 반환
	//fd를 리다이렉트하거나 파이프를 사용해서 한 프로그램의 출력을 다른 프로그램의 입력으로 리다이렉트할 수도 있다.
	//stdin, stdout 에 대한 공부 -> (https://m.blog.naver.com/PostView.nhn?blogId=tipsware&logNo=220980651156&proxyReferer=https:%2F%2Fwww.google.com%2F)
	shell.out = dup(STDOUT);
	shell.exit = 0;
	shell.ret = 0;
	shell.no_exec = 0;
	init_fds(&shell); //fds들을 모두 -1로 초기화시킨다.
	env_init(&shell, env); //**env로 받은 환경변수들을 t_env구조체 안에 정리한다.
	// 환경변수 = 젼역 bash 프로그램에서 통용될 수 있는 변수 (export 붙이면 해당 터미널에서, '$/HOME/.bashrc' 에 저장하면 모든 bash 에서 통용 가능)
	// enviroment(환경변수) 에 관한 공부 -> https://ehpub.co.kr/tag/environ-%EB%B3%80%EC%88%98/
	//secret_env_init(&shell, env);
	increment_shell_level(shell.env);
	while (shell.exit == 0)
	{
		sig_init(); //g_sig 구조체 요소 모두 0으로 초기화
		parse(&shell);
		if (shell.start != NULL && check_line(&shell, shell.start))
			minishell(&shell);
		free_token(shell.start);
	}
	free_env(shell.env);
	free_env(shell.secret_env);
	return (shell.ret);
}

