/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:30:28 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 17:53:39 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ptr_size(const char *s, char c)
{
	size_t				i;
	size_t				word_cnt;

	i = 0;
	word_cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			word_cnt++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (word_cnt);
}

static char				*ft_strndup(const char *str, size_t size)
{
	char				*new;
	size_t				i;

	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void				*strfree(char **ptrarr)
{
	size_t				i;

	i = 0;
	while (ptrarr[i] != NULL)
	{
		free(ptrarr[i]);
		i++;
	}
	free(ptrarr);
	return (NULL);
}

char					**ft_split(char const *s, char c)
{
	char				**splitstr;
	size_t				word_cnt;
	size_t				char_cnt;

	if (!s)
		return (NULL);
	if (!(splitstr = (char **)malloc(sizeof(char *) * (ptr_size(s, c) + 1))))
		return (NULL);
	word_cnt = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			char_cnt = 0;
			while (s[char_cnt] != '\0' && s[char_cnt] != c)
				char_cnt++;
			if (!(splitstr[word_cnt++] = ft_strndup(s, char_cnt)))
				return (strfree(splitstr));
			s += char_cnt;
		}
	}
	splitstr[word_cnt] = NULL;
	return (splitstr);
}
