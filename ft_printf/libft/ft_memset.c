/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:24:16 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 17:25:15 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *ptr, int value, size_t byte)
{
	unsigned char	*str;
	unsigned char	set_value;
	size_t			i;

	str = (unsigned char *)ptr;
	set_value = (unsigned char)value;
	i = 0;
	while (i < byte)
	{
		str[i] = set_value;
		i++;
	}
	return (ptr);
}
