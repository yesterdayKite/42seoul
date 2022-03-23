/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:25:56 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:25:58 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void				parse_typenbr(t_inf *inf)
{
	if (inf->type == 'c')
		inf->typenbr = 0;
	else if (inf->type == 's')
		inf->typenbr = 1;
	else if (inf->type == 'p')
		inf->typenbr = 2;
	else if (inf->type == 'd' || inf->type == 'i')
		inf->typenbr = 3;
	else if (inf->type == 'u')
		inf->typenbr = 4;
	else if (inf->type == 'x' || inf->type == 'X')
		inf->typenbr = 5;
	else if (inf->type == '%')
		inf->typenbr = 6;
	else if (inf->type == 'n')
		inf->typenbr = 7;
	else if (inf->type == 'f')
		inf->typenbr = 8;
	else if (inf->type == 'g')
		inf->typenbr = 9;
	else if (inf->type == 'e')
		inf->typenbr = 10;
}

void				parse(const char *fmt, t_inf *inf, t_tot *tot)
{
	tot->i++;
	parse_flag(fmt, inf, tot);
	parse_width(fmt, inf, tot);
	parse_preci(fmt, inf, tot);
	parse_add(fmt, inf, tot);
	parse_type(fmt, inf, tot);
	if (!inf->type)
	{
		tot->error = TRUE;
		return ;
	}
	check(inf);
	parse_typenbr(inf);
}

void				put(t_inf *inf, t_tot *tot)
{
	void			(*farr[11])(t_inf *, t_tot *);

	farr[0] = put_c;
	farr[1] = put_s;
	farr[2] = put_p;
	farr[3] = put_d;
	farr[4] = put_u;
	farr[5] = put_x;
	farr[6] = put_pct;
	farr[7] = put_n;
	farr[8] = put_f;
	farr[9] = put_g;
	farr[10] = put_e;
	farr[inf->typenbr](inf, tot);
}

void				writeto(const char *fmt, t_tot *tot)
{
	while (fmt[tot->i] != '\0')
	{
		if (fmt[tot->i] == '%')
			return ;
		pf_putchar(tot, fmt[tot->i]);
		tot->i++;
	}
}

int					ft_printf(const char *fmt, ...)
{
	t_inf			inf;
	t_tot			tot;

	ft_bzero(&tot, sizeof(t_tot));
	va_start(tot.ap, fmt);
	while (fmt[tot.i] != '\0')
	{
		if (fmt[tot.i] == '%')
		{
			ft_bzero(&inf, sizeof(t_inf));
			parse(fmt, &inf, &tot);
			put(&inf, &tot);
			if (tot.error)
				return (ERROR);
		}
		else
			writeto(fmt, &tot);
	}
	va_end(tot.ap);
	return (tot.total);
}
