/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 22:31:11 by jae               #+#    #+#             */
/*   Updated: 2021/01/27 21:22:54 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
envp는 프로세스가 실행될 때 받아온 최초의  환경변수를 개발자가 확인할 수 있도록 제공됨.
프로세스가 실행되면, 시스템으로부터 환경변수 정보를 받아서 이 정보를 바탕으로 실행이 된다.
주로 쉘에서 실행된 프로세스이면 시스템 기본 환경변수를 받고, 부모프로세스로부터 환경변수 값을 그대로 물려 받게 된다.
환경변수 조작 함수(setenv(), unsetenv(), clearenv() )등으로 환경변수 조작이 가능한데,
해당 프로세스의 환경변수가 변경되는 것이지, 실제 시스템의 환경변수가 변경되는 것은 아니다.
*/

int				env_init(t_shell *shell, char **env_arr)
{
	t_env		*env;
	t_env		*new;
	int			i;

	if (!(env = malloc(sizeof(t_env))))
		return (1);
	env->value = ft_strdup(env_arr[0]);
	env->next = NULL;
	shell->env = env;
	i = 1;
	while (env_arr && env_arr[0] && env_arr[i])
	{
		if (!(new = malloc(sizeof(t_env))))
			return (1);
		new->value = ft_strdup(env_arr[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	return (0);
}

/*
int				secret_env_init(t_shell	*shell, char **env_arr)
{
	t_env		env;
	t_env		*new;
	int			i;

	if (!(env = malloc(sizoef(t_env))))
		return (1);
	env->value = ft_strdup(env_arr[0]);
	env->next = NULL;
	shell->next = NULL;
	i = 1;
	while (env_array && env_array[0] && env_array[i])
	{
		if (!(new = malloc(sizeof(t_env))))
			return (1);
		new->value = ft_strdup(env_array[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	return (0);
}
*/
