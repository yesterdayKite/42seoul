/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_g_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:26:48 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:26:50 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void			cut_g_str(t_flo *flo, t_inf *inf, t_tot *tot)
{
	int				i;
	char			*new;

	if (!ft_strchr(flo->str, '.'))
		return ;
	i = flo->len - 1;
	while (flo->str[i] == '0')
		i--;
	if (i == flo->len - 1)
		return ;
	if (flo->str[i] == '.' && !inf->sharp)
		i--;
	i++;
	if (!(new = ft_substr(flo->str, 0, (size_t)i)))
	{
		tot->error = TRUE;
		return ;
	}
	free(flo->str);
	flo->str = new;
	flo->len = i;
}

static void			put_g_str(t_flo *flo, t_inf *inf, t_tot *tot)
{
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - flo->len
						- flo->elen - inf->signbyte);
	if (flo->is_minus)
		pf_putchar(tot, '-');
	else if (inf->sign)
		pf_putchar(tot, inf->sign);
	if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - flo->len
						- flo->elen - inf->signbyte);
	pf_putstr(tot, flo->str, flo->len);
	if (flo->elen != 0)
		put_e_e(tot, flo->e);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - flo->len
						- flo->elen - inf->signbyte);
}

void				get_g_e(t_flo *flo, t_inf *inf)
{
	if (flo->f < 0)
	{
		flo->is_minus = TRUE;
		flo->f *= -1.0;
	}
	if (flo->is_minus || (!flo->is_minus && inf->sign))
		inf->signbyte++;
	flo->tmp = flo->f;
	if (flo->tmp >= 1.0)
	{
		while (flo->tmp / ft_power(10, flo->e) >= 10.0)
			flo->e++;
	}
	else if (flo->tmp != 0.0)
	{
		while (flo->tmp < 1.0)
		{
			flo->tmp *= 10;
			flo->e--;
		}
	}
}

static void			make_g_f_len(t_flo *flo, t_inf *inf, t_tot *tot)
{
	double			tmp;

	flo->cnt = 1;
	if ((long long)flo->f != 0)
	{
		while (flo->f / ft_power(10, flo->cnt - 1) >= 10.0)
			flo->cnt++;
		inf->preci -= flo->cnt;
	}
	else
	{
		tmp = flo->f * 10;
		while ((char)tmp == 0)
		{
			tmp *= 10;
			flo->cnt++;
		}
		inf->preci += flo->cnt - 1;
	}
	flo->len = flo->cnt;
	if (!(inf->preci == 0 && !inf->sharp))
		flo->len++;
	flo->len += inf->preci;
	if (!(flo->str = (char *)malloc(sizeof(char) * flo->len + 1)))
		tot->error = TRUE;
}

void				put_g(t_inf *inf, t_tot *tot)
{
	t_flo			flo;

	ft_bzero(&flo, sizeof(t_flo));
	flo.f = va_arg(tot->ap, double);
	get_g_e(&flo, inf);
	if (flo.e < -4 || flo.e >= inf->preci)
	{
		flo.e = 0;
		inf->preci--;
		make_e_len(&flo, inf, tot);
		make_e_str(&flo, inf);
		make_e_rnd(&flo);
	}
	else
	{
		make_g_f_len(&flo, inf, tot);
		make_f_str(&flo, inf);
		make_f_rnd(&flo, tot);
	}
	if (tot->error)
		return ;
	cut_g_str(&flo, inf, tot);
	put_g_str(&flo, inf, tot);
	free(flo.str);
}
