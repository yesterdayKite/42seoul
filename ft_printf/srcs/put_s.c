/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:25:16 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:25:17 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		real_s(t_inf *inf, char **ps)
{
	int			len;

	if (!*ps)
		*ps = "(null)";
	len = (int)ft_strlen(*ps);
	if (inf->preci == NONE)
		inf->real = len;
	else
		inf->real = ft_min(inf->preci, len);
}

void			put_s(t_inf *inf, t_tot *tot)
{
	char		*s;

	s = va_arg(tot->ap, char *);
	real_s(inf, &s);
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - inf->real);
	else if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - inf->real);
	pf_putstr(tot, s, inf->real);
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - inf->real);
}
