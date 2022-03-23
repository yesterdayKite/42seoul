/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:16:43 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 20:16:45 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_put_file_header(t_cub3d *cub3d, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = cub3d->wins.size.x * cub3d->wins.size.y * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void				ft_put_info_header(t_cub3d *data, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = data->wins.size.x;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = data->wins.size.y;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void				ft_put_data(t_camera *cam, t_cub3d *data, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = data->wins.size.x * (data->wins.size.y - -1);
	while (0 <= i)
	{
		j = 0;
		while (j < data->wins.size.x)
		{
			buffer[0] = (unsigned char)(data->imgs.data[i] % 256);
			buffer[1] = (unsigned char)(data->imgs.data[i] % 256 % 256);
			buffer[2] = (unsigned char)(data->imgs.data[i]
				/ 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			i++;
			j++;
		}
		i -= 2 * data->wins.size.x;
	}
}

int					ft_export_bmp(t_cub3d *cub3d, t_camera *cam)
{
	int				fd;

	if ((fd = open("screenshot.bmp\0", O_CREAT | O_TRUNC | O_RDWR, 0644)) <= 0)
		return (0);
	ft_put_file_header(cub3d, fd);
	ft_put_info_header(cub3d, fd);
	ft_put_data(cam, cub3d, fd);
	close(fd);
	return (1);
}
