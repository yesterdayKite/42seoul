/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 16:04:34 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 17:32:57 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t cnt, size_t per)
{
	void			*new;

	if (!(new = malloc(cnt * per)))
		return (NULL);
	return (ft_memset(new, 0, cnt * per));
}
