/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:11:01 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:11:02 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

static t_sprite		*ft_smalloc(t_cub3d *cub3d)
{
	return ((t_sprite *)malloc(sizeof(t_sprite)
	* cub3d->map.nb_sprites));
}

static void			xyi_zero(int *x, int *y, int *i)
{
	x = 0;
	y = 0;
	i = 0;
}

static void			sprite_init(t_cub3d *cub3d)
{
	int		i;

	i = 0;
	while (i < cub3d->map.nb_sprites)
	{
		pos_init(&cub3d->sprite[i].pos, 0, 0);
		i++;
	}
}

void				get_sprites(t_cub3d *cub3d)
{
	int		x;
	int		y;
	int		i;

	xyi_zero(&x, &y, &i);
	cub3d->sprite = ft_smalloc(cub3d);
	sprite_init(cub3d);
	i = 0;
	while (y < cub3d->map.colnum)
	{
		x = 0;
		while (x < cub3d->map.rownum)
		{
			if (i < cub3d->map.nb_sprites && cub3d->map.worldmap[x][y] == 2)
			{
				cub3d->sprite[i].pos.x = (double)(x + 0.5);
				cub3d->sprite[i].pos.y = (double)(y + 0.5);
				cub3d->map.worldmap[x][y] = 0;
				i++;
			}
			x++;
		}
		y++;
	}
}
