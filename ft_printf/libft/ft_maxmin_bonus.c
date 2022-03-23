/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxmin_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:09:26 by jae               #+#    #+#             */
/*   Updated: 2020/08/20 19:00:56 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_size_max(size_t a, size_t b)
{
	return (a > b ? a : b);
}

size_t					ft_size_min(size_t a, size_t b)
{
	return (a > b ? b : a);
}

int						ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int						ft_min(int a, int b)
{
	return (a > b ? b : a);
}
