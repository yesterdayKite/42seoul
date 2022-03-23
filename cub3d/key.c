/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 01:34:19 by jae               #+#    #+#             */
/*   Updated: 2020/12/02 01:34:21 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				key_press(int keycode, t_move *move)
{
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_FORWARD || keycode == KEY_W)
		move->move.x = 1;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		move->move.y = 1;
	if (keycode == KEY_A)
		move->side_move.x = 1;
	else if (keycode == KEY_D)
		move->side_move.y = 1;
	if (keycode == KEY_LEFT)
		move->rotate.x = 1;
	else if (keycode == KEY_RIGHT)
		move->rotate.y = 1;
	return (0);
}

int				key_release(int keycode, t_move *move)
{
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_FORWARD || keycode == KEY_W)
		move->move.x = 0;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		move->move.y = 0;
	if (keycode == KEY_A)
		move->side_move.x = 0;
	else if (keycode == KEY_D)
		move->side_move.y = 0;
	if (keycode == KEY_LEFT)
		move->rotate.x = 0;
	else if (keycode == KEY_RIGHT)
		move->rotate.y = 0;
	return (0);
}

void			key_handling(t_cub3d *cub3d)
{
	t_move		*move;
	t_camera	*camera;
	double		olddirx;
	double		oldplanex;

	move = &cub3d->move;
	camera = &cub3d->camera;
	pos_init(&camera->old_pos, camera->pos.x, camera->pos.y);
	if (move->move.x == 1)
		move_cam(&cub3d->map, camera, camera->movespeed);
	if (move->move.y == 1)
		move_cam(&cub3d->map, camera, -camera->movespeed);
	if (move->side_move.x == 1)
		move_to_side(&cub3d->map, camera, -camera->movespeed);
	if (move->side_move.y == 1)
		move_to_side(&cub3d->map, camera, camera->movespeed);
	if (move->rotate.y == 1)
		rot_cam(camera, camera->plane.x, camera->pos_dir.x, -camera->rotspeed);
	if (move->rotate.x == 1)
		rot_cam(camera, camera->plane.x, camera->pos_dir.x, camera->rotspeed);
	pos_init(&camera->pos, camera->old_pos.x, camera->old_pos.y);
}
