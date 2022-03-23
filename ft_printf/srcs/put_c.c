/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:24:46 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:24:48 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				put_c(t_inf *inf, t_tot *tot)
{
	char			c;

	c = (char)va_arg(tot->ap, int);
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - 1);
	else if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - 1);
	pf_putchar(tot, c);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - 1);
}
