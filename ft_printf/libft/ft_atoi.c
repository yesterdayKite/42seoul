/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 15:18:58 by yopark            #+#    #+#             */
/*   Updated: 2020/04/05 02:21:28 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					skip_space_and_sign(const char *str, size_t *p_i)
{
	while ((9 <= str[*p_i] && str[*p_i] <= 13) || str[*p_i] == 32)
		(*p_i)++;
	if (str[*p_i] == '-')
	{
		(*p_i)++;
		return (TRUE);
	}
	else if (str[*p_i] == '+')
		(*p_i)++;
	return (FALSE);
}

int					ft_atoi(const char *str)
{
	size_t			i;
	int				is_minus;
	long long		result;

	i = 0;
	is_minus = skip_space_and_sign(str, &i);
	result = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		if (is_minus && result > 2147483648)
			return (0);
		if (!is_minus && result > 2147483647)
			return (-1);
		i++;
	}
	return (is_minus ? (int)-result : (int)result);
}
