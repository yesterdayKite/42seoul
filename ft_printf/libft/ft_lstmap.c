/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 16:48:25 by yopark            #+#    #+#             */
/*   Updated: 2020/04/04 19:40:49 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *))
{
	t_list			*head_lst;
	t_list			*tmp;

	if (!(lst && f))
		return (NULL);
	head_lst = NULL;
	while (lst != NULL)
	{
		if (!(tmp = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&head_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&head_lst, tmp);
		lst = lst->next;
	}
	return (head_lst);
}
