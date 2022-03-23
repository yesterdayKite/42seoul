/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:10:16 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:10:17 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				close_game(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->wins.mlx, cub3d->imgs.img);
	mlx_destroy_window(cub3d->wins.mlx, cub3d->wins.win);
	exit(1);
	return (0);
}

void			main_loop(t_cub3d *cub3d)
{
	key_handling(cub3d);
	draw(cub3d);
	if (cub3d->save == 1)
	{
		if (ft_export_bmp(cub3d, &cub3d->camera) == 1)
		{
			ft_printf("--save function executed!\n");
			exit(1);
		}
	}
	mlx_put_image_to_window(cub3d->wins.mlx,\
	cub3d->wins.win, cub3d->imgs.img, 0, 0);
}

int				error_msg(int e)
{
	if (e == 0)
		write(1, "Please enter a map file.\n", 24);
	else if (e == 1)
		write(1, "Please enter a correct argument.\n", 33);
	else if (e == 2)
		write(1, "Map file error.\n", 16);
	exit(1);
	return (0);
}

int				main(int ac, char **av)
{
	t_cub3d		cub3d;

	if (ac != 2 && ac != 3)
		return (error_msg(0));
	cub3d.save = 0;
	cub3d.wins.mlx = mlx_init();
	if (!(file_parser(&cub3d, av[1])))
		return (error_msg(2));
	if (av[2])
		cub3d.save = ((ft_strncmp(av[2], "--save", 6) == 0) ? 1 : 0);
	if (ac == 3 && cub3d.save == 0)
		return (error_msg(1));
	ft_init(&cub3d);
	mlx_hook(cub3d.wins.win, 2, 0, &key_press, &cub3d.move);
	mlx_hook(cub3d.wins.win, 3, 0, &key_release, &cub3d.move);
	ft_printf(">-------------------<\n");
	ft_printf("> Rendering......");
	mlx_loop_hook(cub3d.wins.mlx, (void *)main_loop, &cub3d);
	mlx_loop(&cub3d.wins.mlx);
}
