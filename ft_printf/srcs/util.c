/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:15:04 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:15:07 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				pf_putchar(t_tot *tot, char c)
{
	ft_putchar(c);
	tot->total++;
}

void				pf_putstr(t_tot *tot, char *s, int len)
{
	int				i;

	i = 0;
	while (i < len)
	{
		pf_putchar(tot, s[i]);
		i++;
	}
}

void				pf_putblank(t_tot *tot, char c, int times)
{
	int			i;

	if (times <= 0)
		return ;
	i = 1;
	while (i <= times)
	{
		pf_putchar(tot, c);
		i++;
	}
}
