/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:57:50 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/05 16:55:25 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
	}
	else
	{
		if (!(lst->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
		lst->next = NULL;
	}
	return (lst);
}
