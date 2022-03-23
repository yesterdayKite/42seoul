/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 18:12:24 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 18:24:32 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_in_set(char c, const char *set)
{
	size_t			i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char			*new;
	size_t			start;
	size_t			finish;
	size_t			i;

	if (!(s1 && set))
		return (NULL);
	if (s1[0] == '\0')
		return ((char *)ft_calloc(1, sizeof(char)));
	start = 0;
	while (is_in_set(s1[start], set))
		start++;
	finish = ft_strlen(s1) - 1;
	while (start <= finish && is_in_set(s1[finish], set))
		finish--;
	if (!(new = (char *)malloc(sizeof(char) * (finish - start + 2))))
		return (NULL);
	i = start;
	while (i <= finish)
	{
		new[i - start] = s1[i];
		i++;
	}
	new[i - start] = '\0';
	return (new);
}
