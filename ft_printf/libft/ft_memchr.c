/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:13:51 by yopark            #+#    #+#             */
/*   Updated: 2020/04/11 16:47:33 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *ptr, int arg, size_t byte)
{
	const unsigned char	*str;
	unsigned char		tgt;
	size_t				i;

	str = (const unsigned char *)ptr;
	tgt = (unsigned char)arg;
	i = 0;
	while (i < byte)
	{
		if (str[i] == tgt)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
