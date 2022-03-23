/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 16:15:10 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 18:41:05 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_isalnum(int arg)
{
	if (ft_isalpha(arg))
		return (ft_isalpha(arg));
	else if (ft_isdigit(arg))
		return (4);
	else
		return (FALSE);
}
