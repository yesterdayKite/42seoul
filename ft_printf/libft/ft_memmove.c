/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:21:11 by yopark            #+#    #+#             */
/*   Updated: 2020/04/05 02:23:57 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src,
							size_t byte)
{
	unsigned char		*dststr;
	const unsigned char	*srcstr;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	dststr = (unsigned char *)dst;
	srcstr = (const unsigned char *)src;
	if (byte == 0)
		return (dst);
	if (srcstr < dststr)
	{
		i = byte;
		while (i-- > 0)
			dststr[i] = srcstr[i];
	}
	else
	{
		i = -1;
		while (++i < byte)
			dststr[i] = srcstr[i];
	}
	return (dst);
}
