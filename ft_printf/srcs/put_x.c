/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:25:31 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:25:32 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			real_x(t_inf *inf, int cnt)
{
	if (inf->preci == NONE)
	{
		inf->real = cnt;
		if (cnt == 0)
		{
			inf->real++;
			return ;
		}
	}
	else
		inf->real = ft_max(inf->preci, cnt);
	if (inf->sharp && cnt != 0)
		inf->real += 2;
}

static void			put_x_zero(t_inf *inf, t_tot *tot)
{
	real_x(inf, 0);
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - inf->real);
	else if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - inf->real);
	pf_putblank(tot, '0', inf->real);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - inf->real);
}

static void			put_x_nbr(t_inf *inf, t_tot *tot, unsigned int u, int cnt)
{
	if (!u)
	{
		real_x(inf, cnt);
		if (!inf->paste)
			pf_putblank(tot, ' ', inf->width - inf->real);
		if (inf->sharp && inf->type == 'x')
			pf_putstr(tot, "0x", 2);
		else if (inf->sharp && inf->type == 'X')
			pf_putstr(tot, "0X", 2);
		if (inf->paste == '0')
			pf_putblank(tot, '0', inf->width - inf->real);
		pf_putblank(tot, '0', inf->preci - cnt);
		return ;
	}
	put_x_nbr(inf, tot, u / 16, cnt + 1);
	if (inf->type == 'x')
		pf_putchar(tot, HEXA_S[u % 16]);
	else
		pf_putchar(tot, HEXA_B[u % 16]);
	if (!cnt && inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - inf->real);
}

void				put_x(t_inf *inf, t_tot *tot)
{
	unsigned int	u;

	u = va_arg(tot->ap, unsigned int);
	if (!u)
		put_x_zero(inf, tot);
	else
		put_x_nbr(inf, tot, u, 0);
}
