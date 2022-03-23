/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:27:32 by jae               #+#    #+#             */
/*   Updated: 2020/07/24 02:27:33 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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

static int			pf_round_minus_preci(double f, int preci)
{
	int				is_even;
	double			frec;

	preci *= -1;
	is_even = (long long)(f / ft_power(10, preci)) % 2 == 0 ? TRUE : FALSE;
	frec = f - (long long)(f / ft_power(10, preci)) * ft_power(10, preci);
	if (is_even && frec > 5.0 * ft_power(10, preci - 1))
		return (TRUE);
	else if (!is_even && frec >= 5.0 * ft_power(10, preci - 1))
		return (TRUE);
	return (FALSE);
}

int					pf_round_is_up(double f, int preci)
{
	double			frec;
	int				i;
	int				is_even;

	if (preci < 0)
		return (pf_round_minus_preci(f, preci));
	i = 0;
	frec = f - (long long)(f / 10) * 10.0;
	while (i <= preci)
	{
		if (i == preci)
			is_even = (char)frec % 2 == 0 ? TRUE : FALSE;
		frec = (frec - (char)frec) * 10.0;
		i++;
	}
	if (is_even && frec > 5.0)
		return (TRUE);
	else if (!is_even && frec >= 5.0)
		return (TRUE);
	return (FALSE);
}
