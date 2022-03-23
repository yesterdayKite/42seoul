/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:27:00 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:27:01 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hyphen_flag(int contentlen, char *result, char *src)
{
	int i;

	i = 0;
	if (!*src && t_flag.type == 'c' && t_flag.character == '\0')
	{
		result[i] = src[i];
		i++;
	}
	while (i < contentlen && src[i])
	{
		result[i] = src[i];
		i++;
	}
	while (i < contentlen)
	{
		result[i] = ' ';
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_hashwithzero_flag(char *result, char *src)
{
	int i;
	int zeronum;

	zeronum = 0;
	i = 0;
	while (*src == ' ')
		src++;
	while (i < 2)
	{
		result[i] = src[i];
		i++;
	}
	while (zeronum < t_flag.width - t_flag.conlen)
	{
		result[i] = '0';
		i++;
		zeronum++;
	}
	return (result);
}
