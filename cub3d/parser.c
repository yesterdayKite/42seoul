/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:10:46 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:10:47 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_cub(const char *f)
{
	size_t	i;
	int		j;
	char	*c;

	c = ".cub";
	j = 3;
	i = ft_strlen(f);
	i--;
	while (f[i] && j >= 0)
	{
		if (f[i] == c[j] && f[i - 1] != '\0')
		{
			i--;
			j--;
		}
		else
			return (0);
	}
	return (1);
}

static char	*read_file(int fd)
{
	char	buf[4096];
	char	*new;
	int		i;

	if ((i = read(fd, buf, 4096)) <= 0)
	{
		close(fd);
		return (0);
	}
	if (!(new = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_memcpy(new + 0, buf, i);
	new[i] = 0;
	return (new);
}

static char	*jumping(t_cub3d *cub3d, char *file)
{
	jump_env(&file);
	jump_nbrs(&file);
	file++;
	jump_nbrs(&file);
	file++;
	jump_nbrs(&file);
	jump_space(&file);
	jump_env(&file);
	jump_nbrs(&file);
	file++;
	jump_nbrs(&file);
	file++;
	jump_nbrs(&file);
	jump_space(&file);
	return (file);
}

static int	check_file(t_cub3d *cub3d, char *file)
{
	t_opt	opt;
	char	*s;

	cub3d->map.info = 0;
	while (cub3d->map.info != (char)CONFIGURE_COMPLETE)
	{
		jump_space(&file);
		if (!(opt = check_env(file)) || opt == ERROR)
			return (0);
		jump_env(&file);
		if (opt == RES)
			parser_resolution(cub3d, &file);
		if (opt == TEX_NO || opt == TEX_SO || opt == TEX_EA || opt == TEX_WE
		|| opt == TEX_SPR || opt == TEX_F || opt == TEX_C || opt == COL_F
		|| opt == COL_C)
			parser_textures(opt, cub3d, &file);
	}
	s = jumping(cub3d, file);
	cub3d->map.colnum = map_colum_getter(s);
	cub3d->map.rownum = map_row_getter(s);
	cub3d->map.nb_sprites = 0;
	map_generator(s, cub3d);
	return (map_check(cub3d) ? 1 : 0);
}

int			file_parser(t_cub3d *cub, const char *f)
{
	int		fd;
	char	*file;

	if (!is_cub(f))
		return (0);
	if (!(fd = open(f, O_RDONLY)))
		return (0);
	if (!(file = read_file(fd)))
		return (0);
	if (!(check_file(cub, file)))
		return (0);
	free(file);
	return (1);
}
