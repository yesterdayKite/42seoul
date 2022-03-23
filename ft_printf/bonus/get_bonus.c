/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:25:50 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:25:51 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

wint_t					get_c(t_inf *inf, t_tot *tot)
{
	wint_t				c;

	if (inf->add == 'l')
		c = va_arg(tot->ap, wint_t);
	else
		c = (char)va_arg(tot->ap, int);
	return (c);
}

long long				get_n(t_inf *inf, t_tot *tot)
{
	long long			n;

	if (inf->add == 'H')
		n = (char)va_arg(tot->ap, int);
	else if (inf->add == 'h')
		n = (short)va_arg(tot->ap, int);
	else if (inf->add == 'l')
		n = va_arg(tot->ap, long);
	else if (inf->add == 'L')
		n = va_arg(tot->ap, long long);
	else
		n = va_arg(tot->ap, int);
	return (n);
}

unsigned long long		get_u(t_inf *inf, t_tot *tot)
{
	unsigned long long	u;

	if (inf->add == 'H')
		u = (unsigned char)va_arg(tot->ap, unsigned int);
	else if (inf->add == 'h')
		u = (unsigned short)va_arg(tot->ap, unsigned int);
	else if (inf->add == 'l')
		u = va_arg(tot->ap, unsigned long);
	else if (inf->add == 'L')
		u = va_arg(tot->ap, unsigned long long);
	else
		u = va_arg(tot->ap, unsigned int);
	return (u);
}
