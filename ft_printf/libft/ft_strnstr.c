/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 18:05:18 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 19:17:25 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *str, const char *to_find,
						size_t size)
{
	size_t			i;
	size_t			tofsize;

	i = 0;
	tofsize = ft_strlen(to_find);
	if (tofsize == 0)
		return ((char *)str);
	if (tofsize <= ft_strlen(str) && tofsize <= size)
		while (str[i] != '\0' && i <= size - tofsize)
		{
			if (str[i] == to_find[0]
					&& ft_strncmp(&(str[i]), to_find, tofsize) == 0)
				return ((char *)&(str[i]));
			i++;
		}
	return (NULL);
}
