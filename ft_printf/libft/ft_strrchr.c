/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 18:08:13 by yopark            #+#    #+#             */
/*   Updated: 2020/04/11 16:46:11 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *str, int arg)
{
	size_t			i;

	i = ft_strlen(str);
	while (TRUE)
	{
		if (str[i] == arg)
			return ((char *)&(str[i]));
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
