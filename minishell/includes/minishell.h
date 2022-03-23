/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:13:29 by jae               #+#    #+#             */
/*   Updated: 2021/01/27 22:41:55 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3 // 프로젝트의 메인 줄기. 실제 개바 ㄹ되는 곳
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

# define SKIP 1
# define NOSKIP 0

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define BUFFER_SIZE 4096

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define BUFF_SIZE 4096
# define EXPANSION -36
# define ERROR 1
# define SUCCESS 0
# define IS_DIRECTORY 126
# define UNKNOWN_COMMAND 127

extern t_sig g_sig;

typedef	struct	s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef	struct	s_env
{
	char			*value;
	struct s_env	*next;
}					t_env;

typedef	struct s_shell
{
	t_token			*start;
	t_env			*env;
	t_env			*secret_env;
	int				in;
	int				out;
	int				fdin;
	int				fdout;
	int				pipin;
	int				pipout;
	int				pid;
	int				charge;
	int				parent;
	int				last;
	int				ret;
	int				exit;
	int				no_exec;
}					t_shell;

typedef struct s_sig
{
	int				sigint; //signal interupt : 프로세스에 interupt해라. 즉, 차단하라.
						//ctrl+c : 키보드로 프로세스 종료 signint 시그널을 보내는 것이다.
	int				sigquit; // core dump를 남기고 프로세스를 종료시키는 것.
	int				exit_status;
	pid_t			pid; //process id
}					t_sig;

typedef struct	s_expansions
{
	char			*new_arg;
	int				i;
	int				j;
}					t_expansions;

/*
** main
*/
void			redir_and_exec(t_shell *shell, t_token *token);
void			minishell(t_shell *shell);
void			redir(t_shell *shell, t_token *token, int type);
void			input(t_shell *shell, t_token *token);
int				minipipe(t_shell *shell);
void			sig_int(int code);
void			sig_quit(int code);
void			sig_init(void);


/*
** builtins
*/

static void		print_error(char **args);
static char		*get_env_path(t_env *env, const char *var, size_t len);
static int		update_oldpwd(t_env *env);
static int		go_to_path(int option, t_env *env);
int				ft_cd(char **args, t_env *env);
static	int		nb_args(char **args);
int				ft_echo(char **args);
int				ft_env(t_env *env);
void			shell_exit(t_shell *shell, char **cmd);
char			*get_env_name(char *dest, const char *src);
int				ft_pwd(void);
static size_t	env_size(char *env);
static void		free_node(t_shell *shell, t_env *env);
int				ft_unset(char **a, t_shell *shell);

/*
** env
*/

int				env_init(t_shell *shell, char **env_arr);
int				is_env_char(int c);
int				is_valid_env(const char	*env);
int				env_value_len(const char *env);
char			*env_value(char	*env);
char			*get_env_value(char	*arg, t_env	*env);
static int		invalid_lvl(const char *str);
static int		get_lvl(const char *str);
void			increment_shell_level(t_env	*env);


/*
** utils
*/

void		init_fds(t_shell	*shell);

t_token	*next_sep(t_token *token, int skip);
t_token	*next_sep(t_token *token, int skip);
t_token	*next_run(t_token *token, int skip);



/*
** SIGNAL
*/
void			sig_int(int code);
void			sig_quit(int code);
//void			sig_init(void);



/*
** parsing
*/
static int		varlcpy(char *new_arg, const char *env_value, int pos);
static void		insert_var(t_expansions *ex, char *arg, t_env *env, int ret);
char			*expansions(char *arg, t_env *env, int ret);
int				quote_check(t_shell *shell, char **line);
char			*space_alloc(char *line);
char			*space_line(char *line);
void			parse(t_shell	*shell);
void			type_arg(t_token *token, int separator);
void			squish_args(t_shell *shell);
t_token			*get_tokens(char *line);

/*
** utils
*/
int				ret_size(int ret);
int				get_var_len(const char *arg, int pos, t_env *env, int ret);
int				arg_alloc_len(const char *arg, t_env *env, int ret);
char			*get_var_value(const char *arg, int pos, t_env *env, int ret);
void			init_fds(t_shell *shell);
void			reset_std(t_shell *shell);
void			close_fds(t_shell *shell);
void			ft_close(int fd);
void			init_fds(t_shell *shell);
void			free_token(t_token *start);
void			free_env(t_env *env);
void			free_tab(char **tab);
int				is_last_valid_arg(t_token *token);
int				qutoes(char *line, int index);
int				check_line(t_shell *shell, t_token *token);
t_token			*next_sep(t_token *token, int skip);
t_token			*prev_sep(t_token *token, int skip);
t_token			*next_run(t_token *token, int skip);
int				is_type(t_token *token, int type);
int				is_types(t_token *token, char *types);
int				has_type(t_token *token, int type);
int				has_pipe(t_token *token);
t_token			*next_type(t_token *token, int type, int skip);

#endif
