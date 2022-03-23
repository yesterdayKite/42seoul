/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:11:25 by yopark            #+#    #+#             */
/*   Updated: 2020/04/11 16:47:14 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src,
							int arg, size_t byte)
{
	unsigned char		*dststr;
	const unsigned char	*srcstr;
	unsigned char		tgt;
	size_t				i;

	dststr = (unsigned char *)dst;
	srcstr = (const unsigned char *)src;
	tgt = (unsigned char)arg;
	i = 0;
	while (i < byte)
	{
		dststr[i] = srcstr[i];
		if (srcstr[i] == tgt)
			return ((void *)&dststr[i + 1]);
		i++;
	}
	return (NULL);
}
