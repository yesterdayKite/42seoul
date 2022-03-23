/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:09:35 by jae               #+#    #+#             */
/*   Updated: 2020/12/02 01:36:50 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				spr_color(t_cub3d *cub3d, t_dda_sprite *spr, int y)
{
	spr->d = (y) * 256 - cub3d->wins.size.y * 128 + spr->spriteheight * 128;
	spr->texy = ((spr->d * cub3d->map.tex[4].y) / spr->spriteheight) / 256;
	spr->color = cub3d->map.curr_tex[4][cub3d->map.tex[4].x
		* spr->texy + spr->texx];
}

void				fill_horizon(t_cub3d *cub3d, t_horizon *horizon,
		int texture, int y)
{
	int				x;

	x = 1;
	while (x < cub3d->wins.size.x)
	{
		horizon->cellx = (int)(horizon->floor.x);
		horizon->celly = (int)(horizon->floor.y);
		horizon->tx = (int)(cub3d->map.tex[texture].x * (horizon->floor.x - \
		horizon->cellx)) & (cub3d->map.tex[texture].x - 1);
		horizon->ty = (int)(cub3d->map.tex[texture].y * (horizon->floor.y - \
		horizon->celly)) & (cub3d->map.tex[texture].y - 1);
		horizon->floor.x += horizon->floor_step.x;
		horizon->floor.y += horizon->floor_step.y;
		horizon->color = cub3d->map.curr_tex[texture][cub3d->map.tex[texture].x
		* horizon->ty + horizon->tx];
		cub3d->buf[horizon->is_ceiling + (horizon->is_ceiling \
		!= 0 ? -y : y)][x] = horizon->color;
		x++;
	}
}

void				ray_dir(t_cub3d *cub3d, t_horizon *horizon)
{
	horizon->ray_dir_0.x = cub3d->camera.pos_dir.x - cub3d->camera.plane.x;
	horizon->ray_dir_0.y = cub3d->camera.pos_dir.y - cub3d->camera.plane.y;
	horizon->ray_dir_1.x = cub3d->camera.pos_dir.x + cub3d->camera.plane.x;
	horizon->ray_dir_1.y = cub3d->camera.pos_dir.y + cub3d->camera.plane.y;
}

void				draw_horizon(t_cub3d *cub3d, \
t_horizon *horizon, int texture)
{
	int				y;
	int				p;

	if (horizon->is_ceiling != 0)
		y = cub3d->wins.size.y / 2;
	else
		y = 0;
	while (y < cub3d->wins.size.y)
	{
		ray_dir(cub3d, horizon);
		p = y - cub3d->wins.size.y / 2;
		horizon->pos_z = 0.5 * cub3d->wins.size.y;
		horizon->row_dis = horizon->pos_z / p;
		horizon->floor_step.x = horizon->row_dis * (horizon->ray_dir_1.x - \
		horizon->ray_dir_0.x) / cub3d->wins.size.x;
		horizon->floor_step.y = horizon->row_dis * (horizon->ray_dir_1.y - \
		horizon->ray_dir_0.y) / cub3d->wins.size.x;
		horizon->floor.x = cub3d->camera.pos.x + horizon->row_dis *
			horizon->ray_dir_0.x;
		horizon->floor.y = cub3d->camera.pos.y + horizon->row_dis *
			horizon->ray_dir_0.y;
		fill_horizon(cub3d, horizon, texture, y);
		y++;
	}
}

void				draw(t_cub3d *cub3d)
{
	int				x;
	int				y;
	t_horizon		horizon;
	t_ray			ray;

	y = 0;
	horizon.floortexture = 5;
	horizon.ceilingtexture = 6;

	horizon.is_ceiling = 0;
	draw_horizon(cub3d, &horizon, horizon.floortexture);
	horizon.is_ceiling = cub3d->wins.size.y - 1;
	draw_horizon(cub3d, &horizon, horizon.ceilingtexture);
	draw_wall(cub3d, ray, &cub3d->camera);
	draw_sprites(cub3d);
	while (y < cub3d->wins.size.y)
	{
		x = 0;
		while (x < cub3d->wins.size.x)
		{
			cub3d->imgs.data[y * (int)cub3d->wins.size.x + x] =
				cub3d->buf[y][x];
			x++;
		}
		y++;
	}
}
