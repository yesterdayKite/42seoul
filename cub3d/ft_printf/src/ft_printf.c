/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:27:09 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:27:11 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *input, ...)
{
	va_list	ptr;

	va_start(ptr, input);
	t_flag.relen = 0;
	while (*input)
	{
		ft_initialize();
		if (*input != '%')
			t_flag.relen += ft_putchar(*input);
		if (*input == '%')
		{
			input++;
			if (!(t_flag.type = ft_type_getter(input)))
				t_flag.relen += ft_putchar(*input);
			else if (t_flag.type)
			{
				ft_flag_checker(input, ptr, t_flag.type);
				while (*input != t_flag.type && *input)
					input++;
			}
		}
		input++;
	}
	va_end(ptr);
	return (t_flag.relen);
}
