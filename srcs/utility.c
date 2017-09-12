/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:33:40 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/12 14:49:36 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*ft_lstnewtube(void const *content)
{
	t_list	*lst;
	char	**tab;

	tab = (char**)content;
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
		lst->content = tab;
		lst->next = NULL;
	}
	return (lst);
}

void		ft_lstpushtube(t_list **begin_list, void *content)
{
	t_list *lst;

	lst = *begin_list;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = ft_lstnewtube(content);
	}
	else
		*begin_list = ft_lstnewtube(content);
}

int			only_one(char *name, t_wlist *starts)
{
	while (starts && starts->content && !ft_strlen(starts->content))
	{
		ft_putendl(starts->content);
		if (!ft_strcmp(starts->content, name))
			return (-1);
		starts = starts->next;
	}
	return (0);
}
