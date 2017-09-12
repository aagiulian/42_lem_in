/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:21:18 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/12 15:23:56 by agiulian         ###   ########.fr       */
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

void		free_room(void *path, size_t size)
{
	char	*str;
	t_list	*lst;

	lst = (t_list*)path;
	str = (char*)(lst->content);
	(void)size;
	ft_strdel(&str);
	free(path);
}

void		free_tube(void *path, size_t size)
{
	char	*str;
	t_clist	*lst;

	lst = (t_clist*)path;
	str = (char*)(lst->content);
	(void)size;
	ft_strdel(&str);
	free(path);
}

static void	free_path(void *path, size_t size)
{
	char	**tab;
	t_list	*lst;

	lst = (t_list*)path;
	tab = (char**)(lst->content);
	(void)size;
	ft_tabdel(tab);
	free(path);
}

void		free_all(t_lem *map)
{
	if (map->paths)
		ft_lstdel(&map->paths, &free_path);
	ft_strdel(&(map->start_s));
	ft_strdel(&(map->end_s));
	ft_lstdel(&map->rooms, &free_room);
	ft_clstdel(&map->tubes, &free_tube);
	ft_lstdel(&(map->begin), &free_room);
	free(map);
}
