/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:10:22 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:10:23 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_row_getter(char *map)
{
	int	i;
	int	mapindex;
	int	rownum;

	i = 0;
	rownum = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			rownum++;
		i++;
	}
	return (rownum);
}

int		map_colum_getter(char *map)
{
	int	colnum;

	colnum = 0;
	while (*map == '\n')
		map++;
	while (*map != '\n')
	{
		jump_space(&map);
		colnum++;
		map++;
	}
	return (colnum);
}

void	digit_fill(t_cub3d *cub3d, char **temp, int row, int i)
{
	cub3d->map.worldmap[row][i] = ft_atoi(*temp);
	if (cub3d->map.worldmap[row][i] == 2)
		cub3d->map.nb_sprites += 1;
}

void	map_filler(t_cub3d *cub3d, char **temp, int row)
{
	int	i;

	i = 0;
	while (**temp == '\n')
		(*temp)++;
	while (**temp != '\n' && **temp)
	{
		if (**temp == ' ')
			(*temp)++;
		else
		{
			if (ft_isdigit(**temp))
				digit_fill(cub3d, temp, row, i);
			else
			{
				map_err(cub3d);
				cub3d->map.worldmap[row][i] = 0;
				pos_init(&cub3d->camera.pos, row + 0.1, i + 0.1);
				cub3d->map.start_position = 1;
			}
			(*temp)++;
			i++;
		}
	}
	cub3d->map.worldmap[row][i] = 0;
}

void	map_generator(char *temp, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	ft_printf(">-------------------<\n");
	ft_printf("Now creating a map....\n");
	cub3d->map.worldmap = (int **)malloc(sizeof(int *) *
			(cub3d->map.rownum + 1));
	while (i < cub3d->map.rownum)
	{
		cub3d->map.worldmap[i] = (int *)malloc(sizeof(int) *
				(cub3d->map.colnum + 1));
		map_filler(cub3d, &temp, i);
		i++;
	}
	ft_printf("You've created a map! \n");
	ft_printf(">-------------------<\n");
	cub3d->map.worldmap[i] = 0;
}
