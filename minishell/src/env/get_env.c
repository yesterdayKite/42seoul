/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:38:28 by jae               #+#    #+#             */
/*   Updated: 2021/01/14 20:44:14 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				is_env_char(int c)
{
	if (ft_isalnum(c) == 1 || c == '_')
		return (1);
	return (0);
}

int				is_valid_env(const char	*env)
{
	int			i;

	i = 0;
	if (ft_isdigit(env[i] == 1))
		return (0);
	while (env[i] && env[i] != '=')
	{
		if (ft_isalnum(env[i]) == 0) //아무 목록도 존재하지 않을 때
			return (-1);
		i++;
	}
	if (env[i] != '=') //변수 이름이 존재하지 않을 때
		return (2);
	return (1);
}

int				env_value_len(const char *env)
{
	int			i;
	int			cnt;


	cnt = 0;
	i = 0;
	while (env[i] && env[i] != '=') //HOME=/home/ehpub 같은식으로 = 이후부터 나오기 때문에
		i++;
	i += 1;
	while (env[i])
	{
		i++;
		cnt++;
	}
	return (cnt);
}

char			*env_value(char	*env)
{
	int			i;
	int			j;
	int			alloc_size;
	char		*env_value;

	alloc_size = env_value_len(env) + 1;
	if (!(env_value = malloc(sizeof(char) * alloc_size)))
		return (NULL);
}

char			*get_env_value(char	*arg, t_env	*env)
{
	char		env_name[BUFFER_SIZE];
	char		*env_val;

	env_val = ft_strdup("");
	while (env && env->value)
	{
		get_env_name(env_name, env->value);
		if (ft_strcmp(arg, env_name) == 0)
		{
			ft_memdel(env_val);
			env_val = env_value(env->value);
			return (env_val);
		}
		env = env->next;
	}
	return (env_val);
}


