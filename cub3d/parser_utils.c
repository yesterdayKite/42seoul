/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:10:41 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:10:42 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_in_set(char c, char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (c);
		i++;
	}
	return (0);
}

void	jump_space(char **str)
{
	if (**str == ' ' || **str == '\r' || **str == '\n' || **str == '\t')
		(*str)++;
}

void	jump_env(char **str)
{
	if ((ft_strncmp(*str, "NO ", 3)) == 0 || (ft_strncmp(*str, "SO ", 3)) == 0
		|| ((ft_strncmp(*str, "WE ", 3)) == 0) ||
		((ft_strncmp(*str, "EA ", 3)) == 0 || (ft_strncmp(*str, "FT ", 3)) == 0)
		|| (ft_strncmp(*str, "CT ", 3)) == 0)
	{
		(*str)++;
		(*str)++;
		(*str)++;
	}
	if ((ft_strncmp(*str, "R ", 2)) == 0 || (ft_strncmp(*str, "S ", 2)) == 0 ||
		(ft_strncmp(*str, "F ", 2)) == 0 || (ft_strncmp(*str, "C ", 2)) == 0)
	{
		(*str)++;
		(*str)++;
	}
}

void	jump_nbrs(char **file)
{
	while (**file != '\n' && **file != ' ' && **file != '\t'
		&& **file != '\r' && **file != ',')
	{
		if (**file == '0' || **file == '1' || **file == '2' || **file == '3' ||
			**file == '4' || **file == '5' || **file == '6' ||
			**file == '7' || **file == '8' || **file == '9')
			(*file)++;
	}
}

int		check_env(char *str)
{
	if ((ft_strncmp(str, "R ", 2)) == 0)
		return (RES);
	if ((ft_strncmp(str, "NO ", 3)) == 0)
		return (TEX_NO);
	if ((ft_strncmp(str, "SO ", 3)) == 0)
		return (TEX_SO);
	if ((ft_strncmp(str, "WE ", 3)) == 0)
		return (TEX_WE);
	if ((ft_strncmp(str, "EA ", 3)) == 0)
		return (TEX_EA);
	if ((ft_strncmp(str, "S ", 2)) == 0)
		return (TEX_SPR);
	if ((ft_strncmp(str, "FT ", 3)) == 0)
		return (TEX_F);
	if ((ft_strncmp(str, "CT ", 3)) == 0)
		return (TEX_C);
	if ((ft_strncmp(str, "F ", 2)) == 0)
		return (COL_F);
	if ((ft_strncmp(str, "C ", 2)) == 0)
		return (COL_C);
	return (ERROR);
}
