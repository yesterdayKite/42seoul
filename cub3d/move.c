/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:10:32 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:10:33 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			move_cam(t_map *map, t_camera *camera, double move_speed)
{
	if (!map->worldmap[(int)(camera->old_pos.x +
		camera->pos_dir.x * move_speed)][(int)(camera->old_pos.y)])
		camera->old_pos.x += camera->pos_dir.x * move_speed;
	if (!map->worldmap[(int)(camera->old_pos.x)]
		[(int)(camera->old_pos.y + camera->pos_dir.y * move_speed)])
		camera->old_pos.y += camera->pos_dir.y * move_speed;
}

void			move_to_side(t_map *map, t_camera *cam, double move_speed)
{
	if (!map->worldmap[(int)(cam->old_pos.x + cam->pos_dir.y *
		move_speed)][(int)(cam->old_pos.y)])
		cam->old_pos.x += cam->pos_dir.y * move_speed;
	if (!map->worldmap[(int)(cam->old_pos.x)]
		[(int)(cam->old_pos.y + -cam->pos_dir.x * move_speed)])
		cam->old_pos.y += -cam->pos_dir.x * move_speed;
}

void			rot_cam(t_camera *camera, double oldplanex, \
				double olddirx, double rotspeed)
{
	camera->pos_dir.x = camera->pos_dir.x * cos(rotspeed)
	- camera->pos_dir.y * sin(rotspeed);
	camera->pos_dir.y = olddirx * sin(rotspeed)
		+ camera->pos_dir.y * cos(rotspeed);
	camera->plane.x = camera->plane.x * cos(rotspeed)
	- camera->plane.y * sin(rotspeed);
	camera->plane.y = oldplanex * sin(rotspeed)
	+ camera->plane.y * cos(rotspeed);
}
