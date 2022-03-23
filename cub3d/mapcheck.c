/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:10:27 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:10:28 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			map_err(t_cub3d *cub3d)
{
	if (cub3d->map.start_position == 1)
		error_msg(2);
}

static int		row_check(t_cub3d *cub3d)
{
	int			y;

	y = 0;
	ft_printf("woldmap[0][y] :%d.\nworldmap[rownum-1][y] : %d.\n",
		cub3d->map.worldmap[0][y], cub3d->map.worldmap[cub3d->map.rownum - 1]
		[y]);
	while (y < cub3d->map.colnum && cub3d->map.worldmap[0][y]
	&& cub3d->map.worldmap[cub3d->map.rownum - 1][y])
	{
		if (cub3d->map.worldmap[0][y] != 1)
			return (0);
		if (cub3d->map.worldmap[cub3d->map.rownum - 1][y] != 1)
			return (0);
		y++;
	}
	if (y == cub3d->map.colnum)
		return (1);
	ft_printf("You've failed the entry. y: %d colnum: %d rownum: %d\n",
			y, cub3d->map.colnum, cub3d->map.rownum);
	return (0);
}

static int		col_check(t_cub3d *cub3d)
{
	int			x;

	x = 0;
	while (x < cub3d->map.rownum && cub3d->map.worldmap[x]
			[cub3d->map.colnum - 1] && cub3d->map.worldmap[x][0])
	{
		if (cub3d->map.worldmap[x][cub3d->map.colnum - 1] != 1)
			return (0);
		if (cub3d->map.worldmap[x][0] != 1)
			return (0);
		x++;
	}
	return (x == cub3d->map.rownum ? 1 : 0);
}

static int		valid_chr(t_cub3d *cub3d)
{
	int			i;
	int			j;
	int			res;

	i = 0;
	j = 0;
	res = 0;
	while (i < cub3d->map.rownum && ((cub3d->map.worldmap[i][j] >= 0 &&
		cub3d->map.worldmap[i][j] <= 2) ||
		(cub3d->map.worldmap[i][j] == 'N' || cub3d->map.worldmap[i][j] == 'E' ||
		cub3d->map.worldmap[i][j] == 'W' || cub3d->map.worldmap[i][j] == 'S')))
	{
		j = 0;
		while (j < cub3d->map.colnum &&
		((cub3d->map.worldmap[i][j] >= 0 && cub3d->map.worldmap[i][j] <= 4) ||
		(cub3d->map.worldmap[i][j] == 'N' || cub3d->map.worldmap[i][j] == 'E'
		|| cub3d->map.worldmap[i][j] == 'W' ||
		cub3d->map.worldmap[i][j] == 'S')))
		{
			res++;
			j++;
		}
		i++;
	}
	return (res == cub3d->map.rownum * cub3d->map.colnum ? 1 : 0);
}

int				map_check(t_cub3d *cub3d)
{
	if (!(row_check(cub3d)))
		return (00);
	if (!(col_check(cub3d)))
		return (0);
	if (!(valid_chr(cub3d)))
		return (0);
	ft_printf("Walls/Characters are all valid!\n");
	return (1);
}
