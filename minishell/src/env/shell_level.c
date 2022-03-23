/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 22:34:48 by jae               #+#    #+#             */
/*   Updated: 2021/01/27 21:22:43 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		invalid_lvl(const char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
		return (0);
	}
}

static int		get_lvl(const char *str)
{
	int			i;
	int			sign;
	int			num;

	i = 0;
	sign = 1;
	num = 0;
	ft_skip_spacenl(str, &i); // space, \t, \n등의 공백을 건너뛰어준다.
	if (invalid_lvl(str))
		return (0);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

void			increment_shell_level(t_env	*env)
{
	int			shell_level;
	char		env_name[BUFFER_SIZE];
	char		*shlvl;
	char		*shell_level_value;

	shell_level_value = get_env_value("SHLVL", env);
	if (ft_strcmp(shell_level_value, "") == 0)
		return ;
	shell_level = get_lvl(shell_level_value) + 1;
	ft_memdel(shell_level_value);
	while (env && env->next)
	{
		get_env_name(env_name, env->value);
		if (ft_strcmp("SHLVL", env_name) == 0)
		{
			ft_memdel(env->value);
			shlvl = ft_itoa(shell_level);
			env->value = ft_strjoin("SHLVL=", shlvl);
			ft_memdel(shlvl);
			return ;
		}
		env = env->next;
	}
}


