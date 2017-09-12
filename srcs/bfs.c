/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:30:14 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/12 14:38:20 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_new_path(t_lem *map, t_wlist *parent)
{
	char	*path;
	char	**tab;

	if (!(path = ft_strdup(map->end_s)))
		return ;
	while (parent->parent)
	{
		if (parent->weight > 1)
		{
			ft_strdel(&path);
			return ;
		}
		path = ft_strjoin(ft_strjoin(path, " "), parent->content);
		parent->weight++;
		parent = parent->parent;
	}
	tab = ft_strsplit(path, ' ');
	ft_strdel(&path);
	ft_lstpushtube(&map->paths, tab);
	map->mu++;
}

int		add_to_end(char *name, t_wlist *wlist, t_wlist *starts, t_lem *map)
{
	t_wlist *chd;
	t_wlist *parent;

	parent = wlist;
	if (!ft_strcmp(name, map->end_s))
	{
		add_new_path(map, parent);
		return (1);
	}
	if (only_one(name, starts))
		return (0);
	while (wlist->next)
		wlist = wlist->next;
	if (!(chd = (t_wlist*)malloc(sizeof(t_wlist))))
		exit(-1);
	chd->parent = parent;
	chd->next = NULL;
	chd->weight = 0;
	if (!(chd->content = ft_strdup(name)))
		exit(-1);
	wlist->next = chd;
	return (0);
}

void	split(t_clist **tube, t_lem *map)
{
	if (*tube == map->tubes)
		map->tubes = map->tubes->next;
	ft_clstdelone(tube, free_tube);
	*tube = map->tubes;
}

void	fill_list(t_lem *map, t_wlist *wlist, t_wlist *starts)
{
	t_clist *tube;
	char	**tab;
	int		ret;

	ret = 0;
	tube = map->tubes;
	while (tube && ret != 1)
	{
		tab = ft_strsplit(tube->content, '-');
		if (!ft_strcmp(wlist->content, tab[0]))
		{
			ret = add_to_end(tab[1], wlist, starts, map);
			split(&tube, map);
		}
		else if (!ft_strcmp(wlist->content, tab[1]))
		{
			ret = add_to_end(tab[0], wlist, starts, map);
			split(&tube, map);
		}
		else
			tube = tube->next;
		ft_tabdel(tab);
	}
}

void	make_list(t_lem *map, char *start)
{
	t_wlist	*wlist;
	t_wlist *starts;

	wlist = (t_wlist*)malloc(sizeof(t_wlist));
	starts = wlist;
	wlist->content = ft_strdup(start);
	wlist->parent = NULL;
	wlist->next = NULL;
	wlist->weight = 0;
	while (wlist && ft_strcmp(wlist->content, map->end_s))
	{
		wlist = starts;
		while (wlist && wlist->weight)
			wlist = wlist->next;
		if (!wlist)
			break ;
		wlist->weight++;
		fill_list(map, wlist, starts);
	}
	wlist = starts;
	free_wlist(&wlist);
}
