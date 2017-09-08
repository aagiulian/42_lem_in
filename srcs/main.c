/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:25:09 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/08 16:46:11 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ATTENTION A REMETTRE LE NOMBRE DE FOURMIS AU DEBUT DE L'AFFICHAGE
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

int		only_one(char *name, t_wlist *starts)
{
	while (starts && starts->content && !ft_strlen(starts->content))
	{
		ft_putendl(starts->content);
		if (!ft_strcmp(starts->content, name))
		{
			return (-1);
		}
		starts = starts->next;
	}
	return (0);
}

int	add_to_end(char *name, t_wlist *wlist, t_wlist *starts, t_lem *map)
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
	chd->parent = parent;// A MODIF Pour ajouter le parent
	chd->next = NULL;
	chd->weight = 0;
	if (!(chd->content = ft_strdup(name)))
		exit(-1);
	wlist->next = chd;
	return (0);
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
			if (tube == map->tubes)
				map->tubes = map->tubes->next;
			ft_clstdelone(&tube, free_tube);
			tube = map->tubes;
		}
		else if (!ft_strcmp(wlist->content, tab[1]))
		{
			ret = add_to_end(tab[0], wlist, starts, map);
			if (tube == map->tubes)
				map->tubes = map->tubes->next;
			ft_clstdelone(&tube, free_tube);
			tube = map->tubes;
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

t_lem *init_struct(void)
{
	t_lem *map;

	map = (t_lem*)ft_memalloc(sizeof(t_lem));
	map->begin = NULL;
	map->start = 0;
	map->start_s = NULL;
	map->mu = 0;
	map->end_s = NULL;
	map->tubes = NULL;
	map->rooms = NULL;
	map->end = 0;
	map->tube = 0;
	map->tree = NULL;
	map->paths = NULL;
	return (map);
}

int main(int argc, char **argv)
{
	t_lem	*map;
	t_list	*lst;

	argv[0] = 0;
	map = init_struct();
	if (argc != 1)
	{
		ft_putstr("Usage : ./lem-in < {map_file}\n");
		return (0);
	}
	parse(map);
	if (!map->begin || !map->start || !map->end || !map->tube || !map->start_s || !map->end_s)
	{
		free_all(map);
		ft_putendl("ERROR");
		exit(-1);
	}
	make_list(map, map->start_s);
	if (!map->paths)
	{
		free_all(map);
		ft_putendl("ERROR : NO PATH FOUND");
		exit (-1);
	}
	ft_putnbr(map->ant_nb);
	ft_putendl("");
	lst = map->begin;
	while (map->begin)
	{
		ft_putendl((map->begin)->content);
		map->begin = (map->begin)->next;
	}
	map->begin = lst;
	ft_putendl("");
	print_path(map);
	free_all(map);
	//multi_path(map);
	return (0);
}
