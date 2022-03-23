/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:24:44 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:24:45 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t count, size_t size)
{
	unsigned char	*a;
	size_t			len;

	len = count * size;
	if (!(a = malloc(len)))
		return (a);
	ft_bzero(a, len);
	return (a);
}
