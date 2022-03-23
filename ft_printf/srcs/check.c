/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:15:30 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:15:33 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					check(t_inf *inf)
{
	if (ft_strchr("cspuxX%", (int)inf->type))
		inf->sign = '\0';
	if (ft_strchr("csdiu%", (int)inf->type))
		inf->sharp = FALSE;
	if (ft_strchr("diuxX", (int)inf->type)
			&& inf->preci != NONE && inf->paste == '0')
		inf->paste = '\0';
	if (ft_strchr("c%", (int)inf->type))
		inf->preci = NONE;
}
