/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:25:09 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/12 14:49:15 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem		*init_struct(void)
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

static void	parse_all(t_lem *map)
{
	parse(map);
	if (!map->begin || !map->start || !map->end || !map->tube || \
			!map->start_s || !map->end_s)
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
		exit(-1);
	}
}

int			main(int argc, char **argv)
{
	t_lem	*map;

	argv[0] = 0;
	map = init_struct();
	if (argc != 1)
	{
		ft_putstr("Usage : ./lem-in < {map_file}\n");
		return (0);
	}
	parse_all(map);
	print_all(map);
	free_all(map);
	return (0);
}
