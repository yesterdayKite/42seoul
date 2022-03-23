/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:25:02 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:25:04 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			real_p(t_inf *inf, int cnt)
{
	if (inf->preci == NONE)
	{
		inf->real = cnt;
		if (cnt == 0)
			inf->real++;
	}
	else
		inf->real = ft_max(inf->preci, cnt);
	inf->real += ft_strlen("0x");
	inf->signbyte = 2;
}

static void			put_p_zero(t_inf *inf, t_tot *tot)
{
	real_p(inf, 0);
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - inf->real);
	else if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - inf->real);
	pf_putstr(tot, "0x", 2);
	pf_putblank(tot, '0', inf->real - inf->signbyte);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - inf->real);
}

static void			put_p_addr(t_inf *inf, t_tot *tot, long addr, int cnt)
{
	if (!addr)
	{
		real_p(inf, cnt);
		if (!inf->paste)
			pf_putblank(tot, ' ', inf->width - inf->real);
		else if (inf->paste == '0')
			pf_putblank(tot, '0', inf->width - inf->real);
		pf_putstr(tot, "0x", 2);
		pf_putblank(tot, '0', inf->real - inf->signbyte - cnt);
		return ;
	}
	put_p_addr(inf, tot, addr / 16, cnt + 1);
	pf_putchar(tot, HEXA_S[addr % 16]);
	if (!cnt)
		if (inf->paste == '-')
			pf_putblank(tot, ' ', inf->width - inf->real);
}

void				put_p(t_inf *inf, t_tot *tot)
{
	long			addr;

	addr = (long)va_arg(tot->ap, char *);
	if (!addr)
		put_p_zero(inf, tot);
	else
		put_p_addr(inf, tot, addr, 0);
}
