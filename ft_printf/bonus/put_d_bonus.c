/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:26:23 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:26:25 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void			real_d(t_inf *inf, int cnt)
{
	if (inf->preci == NONE)
	{
		inf->real = cnt;
		if (cnt == 0)
			inf->real++;
	}
	else
		inf->real = ft_max(inf->preci, cnt);
	if (!inf->is_plus
			|| (inf->is_plus && (inf->sign == ' ' || inf->sign == '+')))
		inf->signbyte = 1;
}

static void			put_d_zero(t_inf *inf, t_tot *tot)
{
	real_d(inf, 0);
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - inf->real - inf->signbyte);
	if (inf->sign == ' ' || inf->sign == '+')
		pf_putchar(tot, inf->sign);
	if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - inf->real - inf->signbyte);
	pf_putblank(tot, '0', inf->real);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - inf->real - inf->signbyte);
}

static void			put_d_nbr(t_inf *inf, t_tot *tot, long long n, int cnt)
{
	if (!n)
	{
		real_d(inf, cnt);
		if (!inf->paste)
			pf_putblank(tot, ' ', inf->width - inf->real - inf->signbyte);
		if (!inf->is_plus)
			pf_putchar(tot, '-');
		else if (inf->sign == ' ' || inf->sign == '+')
			pf_putchar(tot, inf->sign);
		if (inf->paste == '0')
			pf_putblank(tot, '0', inf->width - inf->real - inf->signbyte);
		pf_putblank(tot, '0', inf->preci - cnt);
		return ;
	}
	put_d_nbr(inf, tot, n / 10, cnt + 1);
	pf_putchar(tot, DECI[ft_abs(n % 10)]);
	if (!cnt && inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - inf->real - inf->signbyte);
}

void				put_d(t_inf *inf, t_tot *tot)
{
	long long		n;

	n = get_n(inf, tot);
	if (n >= 0)
		inf->is_plus = TRUE;
	if (!n)
		put_d_zero(inf, tot);
	else
		put_d_nbr(inf, tot, n, 0);
}
