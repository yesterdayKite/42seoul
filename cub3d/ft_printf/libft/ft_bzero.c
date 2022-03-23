/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:24:38 by jae               #+#    #+#             */
/*   Updated: 2020/11/27 22:24:39 by jae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *ptr, size_t n)
{
	unsigned char	*ptr_temp;

	ptr_temp = (unsigned char *)ptr;
	while ((int)n-- > 0)
		*ptr_temp++ = 0;
}
