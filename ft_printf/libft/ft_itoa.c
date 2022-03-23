/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 16:24:41 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 18:37:57 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_arr_size(int n)
{
	size_t			size;

	if (n == 0)
		return (2);
	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		if (n > 0)
			n /= 10;
		else
			n /= -10;
	}
	size++;
	return (size);
}

static char			*itoa_putnbr(int n, char *arr, size_t size)
{
	size_t			i;

	i = size - 2;
	if (n == 0)
		arr[i] = 0 + '0';
	while (n != 0)
	{
		if (n > 0)
		{
			arr[i] = n % 10 + '0';
			n /= 10;
		}
		else
		{
			arr[i] = n % 10 * (-1) + '0';
			n /= -10;
		}
		i--;
	}
	return (arr);
}

char				*ft_itoa(int n)
{
	size_t			size;
	char			*arr;

	size = get_arr_size(n);
	if (!(arr = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	arr[size - 1] = '\0';
	if (n < 0)
		arr[0] = '-';
	return (itoa_putnbr(n, arr, size));
}
