/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:00:33 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/08 16:16:33 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst_n;
	t_list	*begin_lst;

	if (lst)
	{
		if (!(lst_n = f(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		begin_lst = lst_n;
		if (lst->next)
		{
			lst = lst->next;
			while (lst)
			{
				lst_n->next = f(ft_lstnew(lst->content, lst->content_size));
				lst_n = lst_n->next;
				lst = lst->next;
			}
		}
		return (begin_lst);
	}
	return (NULL);
}
