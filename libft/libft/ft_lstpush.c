/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:19:25 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/18 18:06:25 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **begin_list, void *content, size_t content_size)
{
	t_list *lst;

	lst = *begin_list;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = ft_lstnew(content, content_size);
	}
	else
		*begin_list = ft_lstnew(content, content_size);
}
