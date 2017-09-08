/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:33:40 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/08 16:40:00 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_wlist(t_wlist **alst)
{
	t_wlist	*lst;

	while (*alst)
	{
		lst = (*alst)->next;
		ft_strdel(&((*alst)->content));
		(*alst)->parent = NULL;
		(*alst)->next = NULL;
		free(*alst);
		*alst = NULL;
		*alst = lst;
	}
}

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

void		free_room(void *path, size_t size)
{
	char 	*str;
	t_list	*lst;

	lst = (t_list*)path;
	str = (char*)(lst->content);
	(void)size;
	ft_strdel(&str);
	free(path);
}

void		free_tube(void *path, size_t size)
{
	char 	*str;
	t_clist	*lst;

	lst = (t_clist*)path;
	str = (char*)(lst->content);
	(void)size;
	ft_strdel(&str);
	free(path);
}

static void	free_path(void *path, size_t size)
{
	char 	**tab;
	t_list	*lst;

	lst = (t_list*)path;
	tab = (char**)(lst->content);
	(void)size;
	ft_tabdel(tab);
	free(path);
}

void		free_all(t_lem *map)
{
	ft_lstdel(&map->paths, &free_path);
	ft_strdel(&(map->start_s));
	ft_strdel(&(map->end_s));
	ft_lstdel(&map->rooms, &free_room);
	ft_clstdel(&map->tubes, &free_tube);
	ft_lstdel(&(map->begin), &free_room);
	free(map);
}
