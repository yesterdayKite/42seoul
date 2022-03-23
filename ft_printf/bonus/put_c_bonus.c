/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:26:17 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:26:18 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void				pf_putwchar(t_tot *tot, wint_t c)
{
	if (c <= 0x007F)
		pf_putchar(tot, (char)c);
	else if (c <= 0x07FF)
	{
		pf_putchar(tot, (char)((c >> 6) + 0xC0));
		pf_putchar(tot, (char)((c & 0x3F) + 0x80));
	}
	else if (c <= 0xFFFF)
	{
		pf_putchar(tot, (char)((c >> 12) + 0XE0));
		pf_putchar(tot, (char)(((c >> 6) & 0x3F) + 0x80));
		pf_putchar(tot, (char)((c & 0x3F) + 0x80));
	}
	else if (c <= 0x10FFFF)
	{
		pf_putchar(tot, (char)((c >> 18) + 0xF0));
		pf_putchar(tot, (char)((c >> 12) & 0x3F));
		pf_putchar(tot, (char)((c >> 6) & 0x3F));
		pf_putchar(tot, (char)((c & 0x3F) + 0x80));
	}
}

void				put_c(t_inf *inf, t_tot *tot)
{
	wint_t			c;

	c = get_c(inf, tot);
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - 1);
	else if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - 1);
	pf_putwchar(tot, c);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - 1);
}
