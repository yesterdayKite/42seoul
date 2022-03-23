/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:50:13 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 17:56:44 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*joinstr;
	size_t			i;
	size_t			s1size;

	if (!(s1 && s2))
		return (NULL);
	if (!(joinstr = (char *)malloc(sizeof(char)
				* ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		joinstr[i] = s1[i];
		i++;
	}
	s1size = ft_strlen(s1);
	while (s2[i - s1size] != '\0')
	{
		joinstr[i] = s2[i - s1size];
		i++;
	}
	joinstr[i] = '\0';
	return (joinstr);
}
