/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 18:15:58 by yopark            #+#    #+#             */
/*   Updated: 2020/04/06 02:48:24 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		size_min(size_t a, size_t b)
{
	return (a > b ? b : a);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			subsize;
	char			*substr;
	size_t			i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return ((char *)ft_calloc(1, sizeof(char)));
	subsize = size_min(ft_strlen(s) - (size_t)start, len) + 1;
	if (!(substr = (char *)malloc(sizeof(char) * subsize)))
		return (NULL);
	i = 0;
	while (i < subsize - 1)
	{
		substr[i] = s[(size_t)start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
