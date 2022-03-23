/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:09:44 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:09:45 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		win_img_init(t_win *wins, t_img *img)
{
	wins->win = mlx_new_window(wins->mlx, wins->size.x, wins->size.y,
	"Hello world!");
	pos_init(&img->size, wins->size.x, wins->size.y);
	img->img = mlx_new_image(wins->mlx, img->size.x, img->size.y);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
	&img->line_length, &img->endian);
	return (1);
}

void	ft_init(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	get_sprites(cub3d);
	cub3d->buf = ft_calloc(cub3d->wins.size.y, (sizeof(int *)));
	cub3d->z_buf = ft_calloc(cub3d->wins.size.x, (sizeof(double)));
	while (i < cub3d->wins.size.y)
	{
		cub3d->buf[i] = ft_calloc(cub3d->wins.size.x, (sizeof(int)));
		i++;
	}
	win_img_init(&cub3d->wins, &cub3d->imgs);
	cub3d->camera.movespeed = 0.05;
	cub3d->camera.rotspeed = 0.05;
	cub3d->map.start_position = 0;
	pos_init(&cub3d->camera.pos_dir, -1, 0);
	pos_init(&cub3d->camera.plane, 0, 0.66);
}

void	pos_init(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}
