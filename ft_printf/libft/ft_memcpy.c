/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 18:32:35 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 19:13:10 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t byte)
{
	unsigned char		*dststr;
	const unsigned char	*srcstr;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	dststr = (unsigned char *)dst;
	srcstr = (const unsigned char *)src;
	i = 0;
	while (i < byte)
	{
		dststr[i] = srcstr[i];
		i++;
	}
	return (dst);
}
