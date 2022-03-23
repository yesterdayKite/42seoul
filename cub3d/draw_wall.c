/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:09:29 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:09:30 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			fill_color(t_cub3d *cub3d, t_drawtex *tex, t_ray *ray, int x)
{
	int			color;
	int			y;

	y = tex->draw_start;
	while (y < tex->draw_end)
	{
		tex->tex_y = (int)tex->texpos & (cub3d->map.tex[tex->texnum].y - 1);
		tex->texpos += tex->step;
		color = cub3d->map.curr_tex[tex->texnum][cub3d->map.tex[tex->texnum].y *
			tex->tex_y + tex->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		cub3d->buf[y][x] = color;
		y++;
	}
}

void			calc_wall_tex(t_cub3d *cub3d, t_ray *ray, t_drawtex *tex,
		int x)
{
	tex->line_height = (int)(cub3d->wins.size.y / ray->perpwalldist);
	tex->draw_start = -tex->line_height / 2 + cub3d->wins.size.y / 2;
	if (tex->draw_start < 0)
		tex->draw_start = 0;
	tex->draw_end = tex->line_height / 2 + cub3d->wins.size.y / 2;
	if (tex->draw_end >= cub3d->wins.size.y)
		tex->draw_end = cub3d->wins.size.y - 1;
	if (ray->side == 0)
		tex->wallx = cub3d->camera.pos.y + ray->perpwalldist * ray->dir.y;
	else
		tex->wallx = cub3d->camera.pos.x + ray->perpwalldist * ray->dir.x;
	tex->wallx -= floor(tex->wallx);
	tex->tex_x = (int)(tex->wallx * (double)cub3d->map.tex[tex->texnum].x);
	if (ray->side == 0 && ray->dir.x > 0)
		tex->tex_x = cub3d->map.tex[tex->texnum].x - tex->tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		tex->tex_x = cub3d->map.tex[tex->texnum].x - tex->tex_x - 1;
	tex->step = 1.0 * cub3d->map.tex[tex->texnum].y / tex->line_height;
	tex->texpos = (tex->draw_start - cub3d->wins.size.y /
			2 + tex->line_height / 2) * tex->step;
	fill_color(cub3d, tex, ray, x);
}

void			draw_wall(t_cub3d *cub3d, t_ray ray, t_camera *camera)
{
	int			x;
	t_drawtex	drawtex;

	x = 0;
	while (x < cub3d->wins.size.x)
	{
		ray_init(cub3d, &ray, camera, x);
		get_walldir(&ray, &drawtex);
		calc_wall_tex(cub3d, &ray, &drawtex, x);
		cub3d->z_buf[x] = ray.perpwalldist;
		x++;
	}
}
