/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_details.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:10:37 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:10:38 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parser_resolution(t_cub3d *cub3d, char **file)
{
	if (cub3d->map.info & RES)
		return (0);
	cub3d->wins.size.x = ft_atoi(*file);
	if (cub3d->wins.size.x < MIN_WINX)
		return (0);
	if (cub3d->wins.size.x > MAX_WINX)
		cub3d->wins.size.x = MAX_WINX;
	if ((int)(cub3d->wins.size.x) % 4)
		cub3d->wins.size.x = cub3d->wins.size.x - (int)(cub3d->wins.size.x) % 4;
	jump_nbrs(file);
	jump_space(file);
	cub3d->wins.size.y = ft_atoi(*file);
	if (cub3d->wins.size.y < MIN_WINY)
		return (0);
	if (cub3d->wins.size.y > MAX_WINY)
		cub3d->wins.size.y = MAX_WINY;
	if ((int)cub3d->wins.size.y % 4)
		cub3d->wins.size.y = cub3d->wins.size.y - (int)cub3d->wins.size.y % 4;
	ft_printf("%d, %d\n", (int)cub3d->wins.size.x, (int)cub3d->wins.size.y);
	jump_nbrs(file);
	jump_space(file);
	cub3d->map.info |= RES;
	return (1);
}

void	load_tex(t_cub3d *cub3d, char *file, int i)
{
	int		x;
	int		y;

	y = 0;
	cub3d->map.tex[i].ptr = mlx_xpm_file_to_image(cub3d->wins.mlx,
			file, &cub3d->map.tex[i].x, &cub3d->map.tex[i].y);
	cub3d->map.tex[i].data = (int *)mlx_get_data_addr(cub3d->map.tex[i].ptr,
		&cub3d->map.tex[i].bpp, &cub3d->map.tex[i].size_l,
			&cub3d->map.tex[i].endian);
	cub3d->map.tex[i].bpp /= 8;
	cub3d->map.curr_tex[i] = (int *)ft_calloc((cub3d->map.tex[i].y
				* cub3d->map.tex[i].x), sizeof(int));
	while (y < cub3d->map.tex[i].y)
	{
		x = 0;
		while (x < cub3d->map.tex[i].x)
		{
			cub3d->map.curr_tex[i][(int)cub3d->map.tex[i].x * y + x] =
				cub3d->map.tex[i].data[cub3d->map.tex[i].x * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub3d->wins.mlx, cub3d->map.tex[i].ptr);
}

char	*read_and_cut(char **file)
{
	int		fd;
	char	*buf;

	buf = *file;
	while (**file != '\n' && **file)
		(*file)++;
	if (!(**file))
		return (NULL);
	**file = '\0';
	(*file)++;
	if (!(fd = open(buf, O_RDONLY)))
		return (0);
	if (read(fd, buf, 0) < 0)
		buf = NULL;
	close(fd);
	return (buf);
}

int		load_colors(t_cub3d *cub3d, char **file, t_opt opt)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(*file);
	if (r < 0x0 || r > 0xFF)
		return (0);
	jump_nbrs(file);
	(*file)++;
	g = ft_atoi(*file);
	if (g < 0x0 || g > 0xFF)
		return (0);
	jump_nbrs(file);
	(*file)++;
	b = ft_atoi(*file);
	if (b < 0x0 || b > 0xFF)
		return (0);
	jump_nbrs(file);
	(*file)++;
	if (opt == COL_F)
		cub3d->map.color[0] = r | g << 8 | b << 16;
	if (opt == COL_C)
		cub3d->map.color[1] = r | g << 8 | b << 16;
	return (1);
}

int		parser_textures(t_opt opt, t_cub3d *cub3d, char **file)
{
	char	*texture;

	if (cub3d->map.info & opt)
		return (0);
	if (opt >= TEX_NO && opt <= TEX_C)
		texture = read_and_cut(file);
	if (texture == NULL)
		return (0);
	if (opt == TEX_NO)
		load_tex(cub3d, texture, 0);
	else if (opt == TEX_SO)
		load_tex(cub3d, texture, 1);
	else if (opt == TEX_WE)
		load_tex(cub3d, texture, 2);
	else if (opt == TEX_EA)
		load_tex(cub3d, texture, 3);
	else if (opt == TEX_SPR)
		load_tex(cub3d, texture, 4);
	else if (opt == TEX_F)
		load_tex(cub3d, texture, 5);
	else if (opt == TEX_C)
		load_tex(cub3d, texture, 6);
	else if (opt == COL_F || opt == COL_C)
		load_colors(cub3d, file, opt);
	return ((cub3d->map.info |= (char)opt));
}
