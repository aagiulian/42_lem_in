/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:25:09 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/13 15:33:41 by agiulian         ###   ########.fr       */
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
	map->c = 0;
	map->save = 0;
	map->paths = NULL;
	map->c_p = 0;
	map->c_m = 0;
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

static int	check_args(int argc, char **argv, t_lem *map)
{
	if (argc > 2)
	{
		ft_putstr("Usage : ./lem-in [-p] < {map_file}\n");
		ft_putstr("                  -p : displays the paths\n");
		ft_putstr("                  -m : multi path\n");
		return (-1);
	}
	else if (argc == 2)
	{
		if (!ft_strcmp("-p", argv[1]))
			map->c_p = 1;
		else if (!ft_strcmp("-m", argv[1]))
			map->c_m = 1;
		else
		{
			ft_putstr("Usage : ./lem-in [-p] < {map_file}\n");
			ft_putstr("                  -p : displays the paths\n");
			ft_putstr("                  -m : multi path\n");
			return (-1);
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_lem	*map;

	argv[0] = 0;
	map = init_struct();
	if (check_args(argc, argv, map))
	{
		free_all(map);
		return (0);
	}
	parse_all(map);
	print_all(map);
	free_all(map);
	return (0);
}
