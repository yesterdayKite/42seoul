/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:26:43 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:26:44 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void				make_f_len(t_flo *flo, t_inf *inf, t_tot *tot)
{
	if (flo->f < 0)
	{
		flo->is_minus = TRUE;
		flo->f *= -1.0;
	}
	if (flo->is_minus || (!flo->is_minus && inf->sign))
		inf->signbyte++;
	flo->cnt = 1;
	while (flo->f / ft_power(10, flo->cnt - 1) >= 10.0)
		flo->cnt++;
	flo->len = flo->cnt;
	if (!(inf->preci == 0 && !inf->sharp))
		flo->len++;
	flo->len += inf->preci;
	if (!(flo->str = (char *)malloc(sizeof(char) * flo->len + 1)))
		tot->error = TRUE;
}

void				make_f_str(t_flo *flo, t_inf *inf)
{
	int				i;
	char			digit;

	i = 0;
	flo->tmp = flo->f;
	while (flo->cnt != 0)
	{
		digit = (char)(flo->tmp / ft_power(10, flo->cnt - 1)) + '0';
		flo->str[i++] = digit;
		flo->tmp -= (digit - '0') * ft_power(10, flo->cnt - 1);
		flo->cnt--;
	}
	if (!(inf->preci == 0 && !inf->sharp))
		flo->str[i++] = '.';
	while (i < flo->len)
	{
		flo->tmp = (flo->tmp - (char)flo->tmp) * 10;
		flo->str[i] = (char)flo->tmp + '0';
		i++;
	}
	flo->str[i] = '\0';
	if (pf_round_is_up(flo->f, inf->preci))
		flo->is_up = TRUE;
}

static char			*make_f_new(char *str, int len)
{
	char			*new;
	int				i;

	if (!(new = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	new[0] = '1';
	new[1] = '0';
	i = 2;
	while (i < len)
	{
		new[i] = str[i - 1];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

void				make_f_rnd(t_flo *flo, t_tot *tot)
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
		flo->len++;
		if (!(flo->str = make_f_new(flo->str, flo->len)))
			tot->error = TRUE;
	}
}

void				put_f(t_inf *inf, t_tot *tot)
{
	t_flo			flo;

	ft_bzero(&flo, sizeof(t_flo));
	flo.f = va_arg(tot->ap, double);
	make_f_len(&flo, inf, tot);
	make_f_str(&flo, inf);
	make_f_rnd(&flo, tot);
	if (tot->error)
		return ;
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - flo.len - inf->signbyte);
	if (flo.is_minus)
		pf_putchar(tot, '-');
	else if (inf->sign)
		pf_putchar(tot, inf->sign);
	if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - flo.len - inf->signbyte);
	pf_putstr(tot, flo.str, flo.len);
	free(flo.str);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - flo.len - inf->signbyte);
}
