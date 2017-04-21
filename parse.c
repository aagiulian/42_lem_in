/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:25:09 by agiulian          #+#    #+#             */
/*   Updated: 2017/04/21 17:26:52 by agiulian         ###   ########.fr       */
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

void	parse(t_lem* map)
{
	char *line;

	line = NULL;
	parse_ant(map);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "-"))
			map->tube++;
		if (!ft_strlen(line) || (line[0] != '#' && map->tube && !ft_strstr(line, "-")))
		{
			ft_putendl("STOP PARSE");
			return ;
		}
		if (line[0] == '#')
			check_start_end(map, line);
		ft_lstpush(&map->begin, line, ft_strlen(line) + 1);	
	}
}

int main(int argc, char **argv)
{
	t_lem	*map;

	argv[0] = 0;
	map = (t_lem*)ft_memalloc(sizeof(t_lem));
	map->begin = NULL;
	map->start = 0;
	map->end = 0;
	map->tube = 0;
	if (argc != 1)
	{
		ft_putstr("Usage : ./lem-in < {map_file}\n");
		return (0);
	}
	parse(map);
	if (!map->begin || !map->start || !map->end || !map->tube)
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
