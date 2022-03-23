/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_e_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:26:36 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:26:38 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void				make_e_len(t_flo *flo, t_inf *inf, t_tot *tot)
{
	get_g_e(flo, inf);
	flo->len = 1;
	if (!(inf->preci == 0 && !inf->sharp))
		flo->len++;
	flo->len += inf->preci;
	if (!(flo->str = (char *)ft_calloc(flo->len + 1, sizeof(char))))
		tot->error = TRUE;
	if (pf_round_is_up(flo->f, inf->preci - flo->e))
		flo->is_up = TRUE;
}

void				make_e_str(t_flo *flo, t_inf *inf)
{
	int				i;

	i = 0;
	flo->cnt = flo->e + 2;
	if (flo->e >= 0)
		while (--flo->cnt != 0)
		{
			flo->str[i++] = (char)(flo->tmp / ft_power(10, flo->cnt - 1)) + '0';
			flo->tmp -= (char)(flo->tmp / ft_power(10, flo->cnt - 1))
							* ft_power(10, flo->cnt - 1);
			if (i == 1 && !(inf->preci == 0 && !inf->sharp))
				flo->str[i++] = '.';
		}
	else
	{
		flo->str[i++] = (char)flo->tmp + '0';
		if (!(inf->preci == 0 && !inf->sharp))
			flo->str[i++] = '.';
		flo->tmp -= (char)flo->tmp;
	}
	while (i < flo->len)
	{
		flo->tmp = (flo->tmp - (char)flo->tmp) * 10;
		flo->str[i++] = (char)flo->tmp + '0';
	}
}

void				make_e_rnd(t_flo *flo)
{
	int				i;

	i = flo->len - 1;
	if (flo->str[i] == '.')
		i--;
	if (flo->is_up)
		flo->str[i]++;
	i++;
	while (--i >= 0)
		if (flo->str[i] == 10 + '0')
		{
			if (i == 0)
				break ;
			flo->str[i] = '0';
			if (flo->str[i - 1] != '.')
				flo->str[i - 1]++;
			else
				flo->str[i - 2]++;
		}
	if (flo->str[0] == 10 + '0')
	{
		flo->str[0] = '1';
		flo->e++;
	}
	flo->elen = (flo->e <= -100 || flo->e >= 100) ? 5 : 4;
}

void				put_e_e(t_tot *tot, int e)
{
	bool			is_minus;

	is_minus = FALSE;
	if (e < 0)
	{
		is_minus = TRUE;
		e *= -1;
	}
	pf_putchar(tot, 'e');
	if (is_minus)
		pf_putchar(tot, '-');
	else
		pf_putchar(tot, '+');
	if (e >= 100)
	{
		pf_putchar(tot, (e / 100) + '0');
		e %= 100;
	}
	pf_putchar(tot, (e / 10) + '0');
	pf_putchar(tot, (e % 10) + '0');
}

void				put_e(t_inf *inf, t_tot *tot)
{
	t_flo			flo;

	ft_bzero(&flo, sizeof(t_flo));
	flo.f = va_arg(tot->ap, double);
	make_e_len(&flo, inf, tot);
	make_e_str(&flo, inf);
	make_e_rnd(&flo);
	if (tot->error)
		return ;
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - flo.len - flo.elen - inf->signbyte);
	if (flo.is_minus)
		pf_putchar(tot, '-');
	else if (inf->sign)
		pf_putchar(tot, inf->sign);
	if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - flo.len - flo.elen - inf->signbyte);
	pf_putstr(tot, flo.str, flo.len);
	free(flo.str);
	put_e_e(tot, flo.e);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - flo.len - flo.elen - inf->signbyte);
}
