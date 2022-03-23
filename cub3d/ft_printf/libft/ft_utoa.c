/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:25:58 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:25:59 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_utoa(long long n)
{
	char			*answer;
	int				number;
	long long		dest;

	number = ft_numlen(n);
	dest = n;
	if (!(answer = (char *)malloc(sizeof(char) * (number))))
		return (NULL);
	answer[number] = 0;
	while (number-- > 0)
	{
		answer[number] = dest % 10 + '0';
		dest /= 10;
	}
	if (n == 0)
		answer[0] = '0';
	return (answer);
}
