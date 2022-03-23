/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:06:29 by jae               #+#    #+#             */
/*   Updated: 2020/11/28 16:31:45 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			sprite_util(t_cub3d *cub3d, t_dda_sprite *spr)
{
	int				y;

	y = 0;
	spr->stripe = spr->drawstartx;
	while (spr->stripe < spr->drawendx)
	{
		spr->texx = (int)(256 * (spr->stripe - (-spr->spritewidth /
						2 + spr->spritescreenx))
			* cub3d->map.tex[4].x / spr->spritewidth) / 256;
		if (spr->transformy > 0 && spr->stripe > 0 &&
		spr->stripe < cub3d->wins.size.x && spr->transformy <
		cub3d->z_buf[spr->stripe])
		{
			y = spr->drawstarty;
			while (y < spr->drawendy)
			{
				spr_color(cub3d, spr, y);
				if ((spr->color & 0x00FFFFFF) != 0)
					cub3d->buf[y][spr->stripe] = spr->color;
				y++;
			}
		}
		spr->stripe++;
	}
}

static void		ray_spritexy(t_cub3d *cub3d, int *spriteorder, int i, \
		t_dda_sprite *spr)
{
	spr->spritex = cub3d->sprite[spriteorder[i]].pos.x - cub3d->camera.pos.x;
	spr->spritey = cub3d->sprite[spriteorder[i]].pos.y - cub3d->camera.pos.y;
	spr->invdet = 1.0 / (cub3d->camera.plane.x *
	cub3d->camera.pos_dir.y - cub3d->camera.pos_dir.x * cub3d->camera.plane.y);
}

static void		ray_sprites(t_cub3d *cub3d, int *spriteorder, int i, \
		t_dda_sprite *spr)
{
	ray_spritexy(cub3d, spriteorder, i, spr);
	spr->transformx = spr->invdet * (cub3d->camera.pos_dir.y *
				spr->spritex - cub3d->camera.pos_dir.x * spr->spritey);
	spr->transformy = spr->invdet * (-cub3d->camera.plane.y *
				spr->spritex + cub3d->camera.plane.x * spr->spritey);
	spr->spritescreenx = (int)((cub3d->wins.size.x / 2) *
				(1 + spr->transformx / spr->transformy));
	spr->spriteheight = (int)fabs(cub3d->wins.size.y / (spr->transformy));
	spr->drawstarty = -spr->spriteheight / 2 + cub3d->wins.size.y / 2;
	if (spr->drawstarty < 0)
		spr->drawstarty = 0;
	spr->drawendy = spr->spriteheight / 2 + cub3d->wins.size.y / 2;
	if (spr->drawendy >= cub3d->wins.size.y)
		spr->drawendy = cub3d->wins.size.y - 1;
	spr->spritewidth = (int)fabs((cub3d->wins.size.y / (spr->transformy)));
	spr->drawstartx = -spr->spritewidth / 2 + spr->spritescreenx;
	if (spr->drawstartx < 0)
		spr->drawstartx = 0;
	spr->drawendx = spr->spritewidth / 2 + spr->spritescreenx;
	if (spr->drawendx >= cub3d->wins.size.x)
		spr->drawendx = cub3d->wins.size.x - 1;
	sprite_util(cub3d, spr);
}

void			sort_sprites(int *order, double *dist, int amount)
{
	t_pair			*sprites;
	int				i;

	i = 0;
	sprites = (t_pair *)malloc(sizeof(t_pair) * amount);
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}

void			draw_sprites(t_cub3d *cub3d)
{
	int				*spriteorder;
	double			*spritedistance;
	int				i;
	t_dda_sprite	spr;

	spriteorder = (int *)malloc(sizeof(int) * cub3d->map.nb_sprites);
	spritedistance = (double *)malloc(sizeof(double) * cub3d->map.nb_sprites);
	i = -1;
	while (++i < cub3d->map.nb_sprites)
	{
		spriteorder[i] = i;
		spritedistance[i] = ((cub3d->camera.pos.x - cub3d->sprite[i].pos.x) *
		(cub3d->camera.pos.x - cub3d->sprite[i].pos.x) + (cub3d->camera.pos.y -
		cub3d->sprite[i].pos.y) * (cub3d->camera.pos.y -
		cub3d->sprite[i].pos.y));
	}
	sort_sprites(spriteorder, spritedistance, cub3d->map.nb_sprites);
	i = 0;
	while (i < cub3d->map.nb_sprites)
	{
		ray_sprites(cub3d, spriteorder, i, &spr);
		i++;
	}
	free(spritedistance);
	free(spriteorder);
}
