/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:25:15 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:25:16 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_putstr(char *s, char type, char character)
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	if (type == 'c' && character == '\0' && !*s)
	{
		write(1, s++, 1);
		i++;
		while (*s)
		{
			write(1, s++, 1);
			i++;
		}
	}
	return (i);
}
