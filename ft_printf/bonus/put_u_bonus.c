/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:27:21 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:27:22 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void			real_u(t_inf *inf, int cnt)
{
	if (inf->preci == NONE)
	{
		inf->real = cnt;
		if (cnt == 0)
			inf->real++;
	}
	else
		inf->real = ft_max(inf->preci, cnt);
}

static void			put_u_zero(t_inf *inf, t_tot *tot)
{
	real_u(inf, 0);
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - inf->real);
	else if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - inf->real);
	pf_putblank(tot, '0', inf->real);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - inf->real);
}

static void			put_u_nbr(t_inf *inf, t_tot *tot,
								unsigned long long u, int cnt)
{
	if (!u)
	{
		real_u(inf, cnt);
		if (!inf->paste)
			pf_putblank(tot, ' ', inf->width - inf->real);
		else if (inf->paste == '0')
			pf_putblank(tot, '0', inf->width - inf->real);
		pf_putblank(tot, '0', inf->real - cnt);
		return ;
	}
	put_u_nbr(inf, tot, u / 10, cnt + 1);
	pf_putchar(tot, DECI[u % 10]);
	if (!cnt && inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - inf->real);
}

void				put_u(t_inf *inf, t_tot *tot)
{
	unsigned long long	u;

	u = get_u(inf, tot);
	if (!u)
		put_u_zero(inf, tot);
	else
		put_u_nbr(inf, tot, u, 0);
}
