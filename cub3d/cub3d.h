/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:16:48 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 20:16:49 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>
# include <time.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# include "./ft_printf/inc/ft_printf.h"
# include "./ft_printf/libft/libft.h"

# define VALID_MAP_ELEMENTS "01234NEWS"

typedef enum		e_opt
{
	ERROR = 0,
	RES = 0b00000001,
	TEX_NO = 0b00000010,
	TEX_SO = 0b00000100,
	TEX_WE = 0b00001000,
	TEX_EA = 0b00010000,
	TEX_SPR = 0b00100000,
	COL_F = 0b01000000,
	COL_C = 0b10000000,
	TEX_F = 0b01000000,
	TEX_C = 0b10000000,
	CONFIGURE_COMPLETE = 0b11111111
}					t_opt;

typedef struct		s_pair
{
	double			first;
	int				second;
}					t_pair;

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	t_pos			size;
}					t_win;

typedef struct		s_param
{
	int				key;
}					t_param;

typedef struct		s_move
{
	t_pos			move;
	t_pos			rotate;
	t_pos			side_move;
}					t_move;

typedef struct		s_camera
{
	t_pos			pos;
	t_pos			pos_dir;
	t_pos			plane;
	t_pos			old_pos;

	double			movespeed;
	double			rotspeed;
}					t_camera;

typedef struct		s_wall
{
	double			dist;
	double			x;
	int				dir;
	int				start;
	int				end;
	int				height;
}					t_wall;

typedef struct		s_sprite
{
	t_pos			pos;
	double			x;
	double			y;
	int				height;
}					t_sprite;

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_pos			size;
}					t_img;

typedef struct		s_texture
{
	int				x;
	int				y;
	void			*ptr;
	int				*data;
	int				bpp;
	int				size_l;
	int				endian;
}					t_tex;

typedef struct		s_map
{
	int				info;
	t_tex			tex[7];
	int				*curr_tex[7];
	int				color[2];
	int				start_position;
	int				nb_sprites;
	int				**worldmap;
	int				colnum;
	int				rownum;
}					t_map;

typedef struct		s_ray
{
	double			camera_x;
	t_pos			dir;

	t_pos			map;
	t_pos			sidedist;

	t_pos			deltadist;
	double			perpwalldist;
	t_pos			step;

	int				hit;
	int				side;
}					t_ray;

typedef struct		s_horizon
{
	t_pos			ray_dir_0;
	t_pos			ray_dir_1;
	float			pos_z;
	float			row_dis;
	t_pos			floor_step;
	t_pos			floor;
	int				is_ceiling;
	int				floortexture;
	int				ceilingtexture;
	int				cellx;
	int				celly;
	int				tx;
	int				ty;
	int				color;
}					t_horizon;

typedef struct		s_dda_sprite
{
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstartx;
	int				drawstarty;
	int				drawendx;
	int				drawendy;
	int				spritewidth;
	int				texx;
	int				texy;
	int				stripe;
	unsigned int	color;
	int				d;
}					t_dda_sprite;

typedef struct		s_drawtex
{
	int				texnum;
	double			wallx;
	int				tex_x;
	int				tex_y;
	double			step;
	double			texpos;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_drawtex;

typedef struct		s_cub3d
{
	t_win			wins;
	t_param			param;
	t_move			move;
	t_img			imgs;
	t_camera		camera;
	t_wall			walls;
	t_map			map;
	t_sprite		*sprite;
	int				**buf;
	double			*z_buf;
	int				save;
}					t_cub3d;

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_FORWARD 126
# define KEY_BACKWARD 125
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define MIN_WINX 100
# define MAX_WINX 2560
# define MIN_WINY 100
# define MAX_WINY 1440

/*
** key.c
*/
int					key_press(int keycode, t_move *move);
int					key_release(int	keycode, t_move *move);
void				key_handling(t_cub3d *cub3d);

/*
** error.c
*/

int					error_msg(int e);

int					ft_in_set(char c, char *set);
int					check_env(char *str);
void				jump_space(char **str);
void				jump_env(char **str);
void				jump_nbrs(char **file);

int					file_parser(t_cub3d *cub, const char *f);
int					parser_textures(t_opt opt, t_cub3d *cub3d, char **file);
int					load_colors(t_cub3d *cub3d, char **file, t_opt opt);
char				*read_and_cut(char **file);
void				load_tex(t_cub3d *cub3d, char *file, int i);

int					parser_resolution(t_cub3d *cub3d, char **file);

/*
** move.c
*/
void				move_cam(t_map *map, t_camera *camera, double move_speed);
void				move_to_side(t_map *map, t_camera *cam, double move_speed);
void				rot_cam(t_camera *camera, double oldplanex, \
double olddirx, double rotspeed);

/*
** map_generator.c
*/
int					map_colum_getter(char *map);
int					map_row_getter(char *map);
void				map_generator(char *temp, t_cub3d *cub3d);

/*
** map_check.c
*/
int					map_check(t_cub3d *cub3d);
void				map_err(t_cub3d *cub3d);

/*
** draw_wall.c
*/
void				fill_color(t_cub3d *cub3d, t_drawtex *tex,
					t_ray *ray, int x);
void				calc_wall_tex(t_cub3d *cub3d, t_ray *ray,
					t_drawtex *tex, int x);
void				draw_wall(t_cub3d *cub3d, t_ray ray, t_camera *camera);

/*
** ray.c
*/
void				ray_init(t_cub3d *cub3d, t_ray *ray, t_camera
					*camera, int x);
void				get_walldir(t_ray *ray, t_drawtex *tex);
void				ray_init(t_cub3d *cub3d, t_ray *ray, t_camera
					*camera, int x);

/*
** draw.c
*/
void				draw_horizon(t_cub3d *cub3d, t_horizon *horizon,
					int texture);
void				draw_wall(t_cub3d *cub3d, t_ray ray, t_camera *camera);
void				draw(t_cub3d *cub3d);
void				spr_color(t_cub3d *cub3d, t_dda_sprite *spr, int y);

/*
** bmp.c
*/
int					ft_export_bmp(t_cub3d *cub3d, t_camera *cam);

/*
** sprite.c
*/
void				get_sprites(t_cub3d *cub3d);
void				sort_order(t_pair *orders, int mount);
void				sort_sprites(int *order, double *dist, int amount);

/*
** init.c
*/
void				ft_init(t_cub3d *cub3d);
int					win_img_init(t_win *wins, t_img *img);
void				pos_init(t_pos *pos, double	x, double y);

/*
** sprite_details.c
*/

void				draw_sprites(t_cub3d *cub3d);

#endif
