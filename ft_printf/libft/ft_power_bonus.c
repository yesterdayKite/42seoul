/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 23:05:56 by yopark            #+#    #+#             */
/*   Updated: 2020/08/20 17:08:25 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long			ft_power(int n, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (n * ft_power(n, power - 1));
}
