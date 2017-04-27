/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:25:09 by agiulian          #+#    #+#             */
/*   Updated: 2017/04/27 20:18:32 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// ATTENTION A REMETTRE LE NOMBRE DE FOURMIS AU DEBUT DE L'AFFICHAGE
#include "lem_in.h"

void	check_start_end(t_lem *map, char *line)
{
	if (!ft_strcmp("##start", line))
	{
		if (map->start)
		{
			ft_putendl("ERROR");
			exit(-1);
		}
		map->start = 1;
	}
	if (!ft_strcmp("##end", line))
	{
		if (map->end)
		{
			ft_putendl("ERROR");
			exit(-1);
		}
		map->end = 1;
	}
}

void	parse_ant(t_lem* map)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	map->ant_nb = ft_atoi(line);
	if (!map->ant_nb)
	{
		ft_putendl("ERROR");
		exit(-1);
	}
}

int		check_room(t_lem* map, char *room1, char *room2)
{
	int		count1;
	int		count2;
	t_list	*list;

	list = map->rooms;
	count1 = 0;
	count2 = 0;
	while (list)
	{
		if (!ft_strcmp(room1, list->content))
			count1++;
		else if (!ft_strcmp(room2, list->content))
			count2++;
		list = list->next;
	}
	if (count1 && count2)
		return (0);
	return (-1);
}

int		add_room(char *line, t_lem *map)
{
	char **tab;

	tab = ft_strsplit(line, ' ');
	if (tab[3] || !tab[0] || !tab[1] || !tab[2] || !ft_strisdigit(tab[1]) || !ft_strisdigit(tab[2])) // RAJOUTER FT_STRISDIGIT ET VERIFIER LE L
	{
		//ft_tabdel(&tab);
		return (-1);
	}
	if (map->start == 1 && map->start++)
		map->start_s = line;
	else if (map->end == 1 && map->end++)
		map->end_s = line;
	ft_lstpush(&map->rooms, tab[0], ft_strlen(tab[0]) + 1);
	//ft_tabdel(&tab);
	return (0);
}

int		add_tube(char *line, t_lem *map)
{
	char **tab;

	if (ft_strchr(line, '-') != ft_strrchr(line, '-'))
	{
		map->tube--;
		return (-1);
	}
	tab = ft_strsplit(line, '-');
	if (tab[2] || !tab[0] || !tab[1] || check_room(map, tab[0], tab[1]))
	{
		map->tube--;
		ft_tabdel(&tab);
		return (-1);
	}
	else if (ft_strcmp(tab[0], tab[1]))
	{
	//	ft_tabdel(&tab);
		ft_lstpush(&map->tubes, line, ft_strlen(line) + 1);
		return (0);
	}
	ft_tabdel(&tab);
	map->tube--;
	return (-1);
}

int		store(char *line, t_lem *map)
{
	if (line[0] != '#')
	{
		if (!ft_strstr(line, "-"))
			return (add_room(line, map));
		else
			return (add_tube(line, map));
	}
	return (0);
}

void	parse(t_lem* map)
{
	char *line;

	line = NULL;
	parse_ant(map);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) && line[0] != 'L' && line[0] != '#' && ft_strstr(line, "-"))
			map->tube++;
		if (!ft_strlen(line) || line[0] == 'L' || (line[0] != '#' && map->tube && !ft_strstr(line, "-")))
		{
			ft_putendl("STOP PARSE");
			return ;
		}
		if (line[0] == '#')
			check_start_end(map, line);
		if (store(line, map))
		{
			ft_putendl("STOP PARSE");
			return ;
		}
		ft_lstpush(&map->begin, line, ft_strlen(line) + 1);	
	}
}

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
	while (map->begin)
	{
		ft_putendl((map->begin)->content);
		map->begin = (map->begin)->next;
	}
	return (0);
}
