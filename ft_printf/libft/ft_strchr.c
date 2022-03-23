/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:41:00 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 17:42:40 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *str, int arg)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == arg)
			return ((char *)&(str[i]));
		i++;
	}
	if (arg == '\0')
		return ((char *)&(str[i]));
	return (NULL);
}
