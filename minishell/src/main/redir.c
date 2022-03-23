/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 22:04:17 by jae               #+#    #+#             */
/*   Updated: 2021/01/26 01:48:31 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
리다이렉션 : 명령의 결과를 모니터로 출력하지 않고 파일로 저장할때 리다이렉션 사용
공부자료 : https://webdir.tistory.com/256
*/
void			redir(t_shell *shell, t_token *token, int type)
{
	ft_close(shell->fdout);
	if (type == TRUNC)
		shell->fdout = open(token->str, 0_CREAT | 0_WRONLY | O_TRUNC, S_IRWXU );
		//flag 들의 각 뜻 : https://www.it-note.kr/19
	else
		shell->fdout = open(token->str, 0_CREAT | 0_WRONLY | 0_APPEND, S_IRWXU);
	if (shell->fdout == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(": No such file or directory", STDERR);
		shell->ret = 1;
		shell->no_exec = 1;
		return ;
	}
	dup2(shell->fdout, STDOUT);
}

void			input(t_shell *shell, t_token *token)
{
	ft_close(shell->fdin);
	shell->fdin = open(token->str, 0_RDONLY, S_IRWXU);
	if (shell->fdin == -1)
	{
		ft_putendl_fd("minishell: ", STDERR);
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(": No such file or directory", STDERR);
		shell->ret = 1;
		shell->no_exec = 1;
		return ;
	}
	dup2(shell->fdin, STDIN); //fd 를 복사한다.
}


int		minipipe(t_shell *shell)
{
	pid_t		pid; //process id
	int			pipefd[2];

	pipe(pipefd); // 읽기, 쓰기 할 수 있는 descriptor 생성
	pid = fork(); //자식 프로세스 생성
	/*
	fork로 생성된 자식 프로세스는 자신의 PID 를 가지게 되며, PPID 는 부모프로세스의 PID를 가지게 된다.
	*/
	if (pid == 0) // 성공할 경우, PID가 부모에게 리턴되고, 자식에게는 0이 리턴.
	{
		ft_close(pipefd[1]);
		dub2(pipefd[0], STDIN);
		shell->pipin = pipefd[0];
		shell->pid = -1;
		shell->parent = 0;
		shell->no_exec = 0;
		return (2);
	}
	else //실패할 경우
	{
		ft_close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		shell->pipout = pipefd[1];
		shell->pid = pid;
		shell->last = 0;
		return (1);
	}
}
