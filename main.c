/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:25:09 by agiulian          #+#    #+#             */
/*   Updated: 2017/06/28 14:55:58 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// ATTENTION A REMETTRE LE NOMBRE DE FOURMIS AU DEBUT DE L'AFFICHAGE
#include "lem_in.h"

/*void	create_tree(t_lem *map, char *name)
  {
  char	**tab;
  t_list	*list;

  list = map->tubes;
  if (list->content == NULL)
  return ;
  while (map->tubes)
  {
  if (map->tubes->content)
  {
  tab = ft_strsplit(map->tubes->content, '-');
  if (tab[2] || !tab[0] || !tab[1] || tab[0] == tab[1])
  {
  ft_putendl("ERROR");
  exit(-1);
  }
  if (tab[0] == name)
  add_child(map->tree, tab[0], tab[1]);
  else if (tab[1] == name)
  add_child(map->tree, tab[1], tab[0]);
  if (!ft_strcmp(tab[0], name) || !ft_strcmp(tab[1], name))
  ft_strdel(&map->tubes->content);
  }
  map->tubes = map->tubes

  }
  }*/

void	add_node(char *child, t_tree *current, t_lem *map)
{
	t_tree *chd;

	if (!(chd = (t_tree*)malloc(sizeof(t_tree))))
		exit (-1);
	chd->parent = current;
	chd->sibling = NULL;
	chd->child = NULL;
	chd->next = NULL;
	chd->parents = NULL;
	chd->weight = 0;
	if (!(chd->content = ft_strdup(child)))
		exit(-1);
	if (!current)
		map->tree = chd;
	else if (!current->child)
		current->child = chd; 
	else
	{
		current = current->child;
		while (current->sibling)
			current = current->sibling;
		current->sibling = chd;
	}
}

void	find_path(t_lem *map, t_tree *current)
{
	if (!ft_strcmp(current->content, map->end_s))
	{
		ft_printf("%s", current->content);
		while (current->parent)
		{
			current = current->parent;
			ft_printf(":%s", current->content);
		}
		exit (0);
	}
		if (current->child)
			find_path(map, current->child);
		while (current->sibling)
		{
			current = current->sibling;
			find_path(map, current);
		}
}

/*/ BON A REVOIR void	find_bfs(t_lem *map, t_tree *current)
{
	while (ft_strcmp(current->content, map->end_s))
	{
		if (current->child)
		{
			add current->child
			current = current->child;
			while (current->sibling)
			{
				current = current->sibling;
				add current->sibling;
			}
		}
	}
	if (!ft_strcmp(current->content, map->end_s))
	{
		ft_printf("%s", current->content);
		while (current->parent)
		{
			current = current->parent;
			ft_printf(":%s", current->content);
		}
		exit (0);
	}
}*/

void	create_tree(t_lem *map, char *name, t_tree *current)
{
	t_clist	*tube;
	char	**tab;
//	t_tree	*parent;

	tube = map->tubes;
	while (current)
	{
		name = current->content;
		ft_putendl(name);
		while (tube)
		{
			if (!ft_strcmp(current->content, map->end_s))
				break ;
			ft_putendl(tube->content);
			tab = ft_strsplit(tube->content, '-');
			if (!ft_strcmp(name, tab[0]))
			{
				add_node(tab[1], current, map);
			if (tube == map->tubes)
				map->tubes = map->tubes->next;
				ft_clstdelone(&tube);
				tube = map->tubes;
			}
			else if (!ft_strcmp(name, tab[1]))
			{
				add_node(tab[0], current, map);
			if (tube == map->tubes)
				map->tubes = map->tubes->next;
				ft_clstdelone(&tube);
				tube = map->tubes;;
			}
			else
				tube = tube->next;
		}
		tube = map->tubes;
		if (current->sibling)
			current = current->sibling;
		else if (current->child)
			current = current->child;
		else
			return;
	}
}
/*void	create_tree(t_lem *map, char *name, t_tree *current)
{
	t_clist	*tube;
	char	**tab;

	ft_printf("seek = %s\n", name);
	tube = map->tubes;
	if (!ft_strcmp(name, map->end_s))
		return ;
	if (current && current->child)
	{
		current = current->child;
		while (ft_strcmp(current->content, name))
			current = current->sibling;
	}
	while (tube)
	{
		tab = ft_strsplit(tube->content, '-');
		if (!ft_strcmp(name, tab[0]))
		{
			add_node(tab[1], current, map);
			if (tube == map->tubes)
				map->tubes = map->tubes->next;
			ft_clstdelone(&tube);
			create_tree(map, tab[1], current);
			tube = map->tubes;
		}
		else if (!ft_strcmp(name, tab[1]))
		{
			add_node(tab[0], current, map);
			if (tube == map->tubes)
				map->tubes = map->tubes->next;
			ft_clstdelone(&tube);
			create_tree(map, tab[0], current);
			tube = map->tubes;;
		}
		else
			tube = tube->next;
		//del_tab();
	}
}*/

void	print_tree(t_tree *tree)
{
	if (tree)
	{
		//	ft_printf("node = %s\n", tree->content);
		if (tree->child)
		{
			tree = tree->child;	
			ft_printf("%s child of %s\n", tree->content, tree->parent->content);
			print_tree(tree);
			while (tree->sibling)
			{
				tree = tree->sibling;
				ft_printf("%s child of %s\n", tree->content, tree->parent->content);
				//	ft_printf("sibling = %s\n", tree->content);
				print_tree(tree);
			}
		}
	}
}

int main(int argc, char **argv)
{
	t_lem	*map;

	argv[0] = 0;
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
	add_node(map->start_s, NULL, map);
	create_tree(map, map->start_s, map->tree);
	print_tree(map->tree);
	find_path(map, map->tree);
	ft_putendl("");
	while (map->begin)
	{
		ft_putendl((map->begin)->content);
		map->begin = (map->begin)->next;
	}
	return (0);
}
