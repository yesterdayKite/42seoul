/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:25:43 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:25:45 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void					check(t_inf *inf)
{
	if (ft_strchr("cspuxX%n", (int)inf->type))
		inf->sign = '\0';
	if (ft_strchr("csdiu%n", (int)inf->type))
		inf->sharp = FALSE;
	if (inf->type == 'n' || (ft_strchr("diuxX", (int)inf->type)
			&& inf->preci != NONE && inf->paste == '0'))
		inf->paste = '\0';
	if (ft_strchr("c%n", (int)inf->type))
		inf->preci = NONE;
	if (ft_strchr("fge", (int)inf->type) && inf->preci == NONE)
		inf->preci = 6;
	if (ft_strchr("p%nfge", (int)inf->type)
			|| (ft_strchr("cs", (int)inf->type) && inf->add != 'l'))
		inf->add = '\0';
	if (inf->type == 'n')
		inf->width = 0;
	if (inf->type == 'g' && inf->preci == 0)
		inf->preci = 1;
}
