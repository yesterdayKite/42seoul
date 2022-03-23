/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:54:09 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 18:24:05 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			dstsize;
	size_t			srcsize;
	size_t			i;

	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < srcsize && dstsize + i < size - 1)
		{
			dst[dstsize + i] = src[i];
			i++;
		}
		dst[dstsize + i] = '\0';
	}
	return (size > dstsize ? srcsize + dstsize : srcsize + size);
}
