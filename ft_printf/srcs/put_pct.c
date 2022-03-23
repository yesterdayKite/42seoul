/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:25:08 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:25:10 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				put_pct(t_inf *inf, t_tot *tot)
{
	if (!inf->paste)
		pf_putblank(tot, ' ', inf->width - 1);
	else if (inf->paste == '0')
		pf_putblank(tot, '0', inf->width - 1);
	pf_putchar(tot, '%');
	if (inf->paste == '-')
		pf_putblank(tot, ' ', inf->width - 1);
}
