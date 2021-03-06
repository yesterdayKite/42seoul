/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexchanger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:24:48 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:24:49 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long		ft_hexnumlen(unsigned long num)
{
	int				len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char				*ft_hexchanger(unsigned long num)
{
	char			*hex;
	char			*result;
	int				len;
	int				i;

	len = ft_hexnumlen(num);
	hex = ft_strdup("0123456789ABCDEF");
	result = (char *)malloc(sizeof(char) * len + 1);
	if (num == 0)
	{
		result[0] = '0';
		result[1] = 0;
		free(hex);
		return (result);
	}
	i = len - 1;
	while (i >= 0)
	{
		result[i] = hex[num % 16];
		num /= 16;
		i--;
	}
	result[len] = 0;
	free(hex);
	return (result);
}
