/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:10:55 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:10:56 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_step(t_ray *ray, t_camera *camera, int x, int y)
{
	if (x == 1 || x == -1)
	{
		ray->step.x = x;
		if (x == -1)
			ray->sidedist.x = (camera->pos.x - ray->map.x) * ray->deltadist.x;
		else
			ray->sidedist.x = (ray->map.x + 1.0 - camera->pos.x) *
				ray->deltadist.x;
	}
	else
	{
		ray->step.y = y;
		if (y == -1)
			ray->sidedist.y = (camera->pos.y - ray->map.y) * ray->deltadist.y;
		else
			ray->sidedist.y = (ray->map.y + 1.0 - camera->pos.y) *
				ray->deltadist.y;
	}
}

void	set_step_side(t_ray *ray, t_camera *camera, t_cub3d *cub3d)
{
	if (ray->dir.x < 0)
		set_step(ray, camera, -1, 0);
	else
		set_step(ray, camera, 1, 0);
	if (ray->dir.y < 0)
		set_step(ray, camera, 0, -1);
	else
		set_step(ray, camera, 0, 1);
	while (ray->hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (cub3d->map.worldmap[(int)ray->map.x][(int)ray->map.y] > 0)
			ray->hit = 1;
	}
}

void	ray_init(t_cub3d *cub3d, t_ray *ray, t_camera *camera, int x)
{
	ray->camera_x = 2 * x / (double)cub3d->wins.size.x - 1;
	ray->dir.x = camera->pos_dir.x + camera->plane.x * ray->camera_x;
	ray->dir.y = camera->pos_dir.y + camera->plane.y * ray->camera_x;
	ray->map.x = (int)camera->pos.x;
	ray->map.y = (int)camera->pos.y;
	ray->hit = 0;
	set_step_side(ray, camera, cub3d);
	ray->deltadist.x = fabs(1 / ray->dir.x);
	ray->deltadist.y = fabs(1 / ray->dir.y);
	if (ray->side == 0)
	{
		ray->perpwalldist = (ray->map.x - camera->pos.x + (1 - ray->step.x) / 2)
			/ ray->dir.x;
	}
	else
	{
		ray->perpwalldist = (ray->map.y - camera->pos.y + (1 - ray->step.y) / 2)
			/ ray->dir.y;
	}
}

void	get_walldir(t_ray *ray, t_drawtex *tex)
{
	if (ray->dir.x < 0 && ray->side == 0)
		tex->texnum = 0;
	if (ray->dir.x > 0 && ray->side == 0)
		tex->texnum = 1;
	if (ray->dir.y < 0 && ray->side == 1)
		tex->texnum = 2;
	if (ray->dir.y > 0 && ray->side == 1)
		tex->texnum = 3;
}
