/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:25:09 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/05 22:43:17 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// ATTENTION A REMETTRE LE NOMBRE DE FOURMIS AU DEBUT DE L'AFFICHAGE
#include "lem_in.h"

int		only_one(char *name, t_wlist *starts)
{
	while (starts)
	{
		if (!ft_strcmp(starts->content, name))
			return (-1);
		starts = starts->next;
	}
	return (0);
}

void	add_to_end(char *name, t_wlist *wlist, t_wlist *starts)
{	
	t_wlist *chd;
	t_wlist *parent;
	
	parent = wlist;
	if (only_one(name, starts))
		return ;
	while (wlist->next)
		wlist = wlist->next;
	if (!(chd = (t_wlist*)malloc(sizeof(t_wlist))))
		exit (-1);
	chd->parent = parent;// A MODIF Pour ajouter le parent
	chd->next = NULL;
	chd->weight = 0;
	if (!(chd->content = ft_strdup(name)))
		exit(-1);
	wlist->next = chd;
}

void	fill_list(t_lem *map, t_wlist *wlist, t_wlist *starts)
{
	t_clist *tube;
	char	**tab;

	tube = map->tubes;
	while (tube)
	{
		tab = ft_strsplit(tube->content, '-');
		if (!ft_strcmp(wlist->content, tab[0]))
		{
			add_to_end(tab[1], wlist, starts);
			if (tube == map->tubes)
				map->tubes = map->tubes->next;
			ft_clstdelone(&tube);
			tube = map->tubes;
		}
		else if (!ft_strcmp(wlist->content, tab[1]))
		{
			add_to_end(tab[0], wlist, starts);
			if (tube == map->tubes)
				map->tubes = map->tubes->next;
			ft_clstdelone(&tube);
			tube = map->tubes;
		}
		else
			tube = tube->next;
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
	while (ft_strcmp(wlist->content, map->end_s))
	{
		wlist = starts;
		while (wlist->weight == 1)
			wlist = wlist->next;
		wlist->weight = 1;
		fill_list(map, wlist, starts); 
	}
	wlist = starts;
	while (starts)
	{
		ft_putstr(starts->content);
		starts = starts->next;
	}
	ft_putendl("");
	starts = wlist;
	while (ft_strcmp(starts->content, map->end_s))
		starts = starts->next;
	while (starts->parent)
	{
		ft_putstr(starts->content);
		if (starts->parent)
			ft_putstr(" => ");
		starts = starts->parent;
	}
	ft_putendl(starts->content);
}

t_lem *init_struct(void)
{
	t_lem *map;

	map = (t_lem*)ft_memalloc(sizeof(t_lem));
	map->begin = NULL;
	map->start = 0;
	map->start_s = NULL;
	map->end_s = NULL;
	map->tubes = NULL;
	map->rooms = NULL;
	map->end = 0;
	map->tube = 0;
	map->tree = NULL;
	return (map);
}

int main(int argc, char **argv)
{
	t_lem	*map;

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
		ft_putendl("ERROR");
		exit(-1);
	}
	make_list(map, map->start_s);
	/*
	   add_node(map->start_s, NULL, map);
	   create_tree(map, map->start_s, map->tree);
	   print_tree(map->tree);
	   find_path(map, map->tree);
	   ft_putendl("");
	   */
	while (map->begin)
	{
		ft_putendl((map->begin)->content);
		map->begin = (map->begin)->next;
	}
	return (0);
}
