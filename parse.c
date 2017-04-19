/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:25:09 by agiulian          #+#    #+#             */
/*   Updated: 2017/04/19 20:08:59 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_ant(t_lem* map)
{
	char *line;
	
	line = NULL;
	get_next_line(0, &line);
	map->ant_nb = ft_atoi(line);
	if (!map->ant_nb)
	{
		ft_putstr("Missing ant number\n");
		exit(-1);
	}
	ft_printf("ant = %i\n", map->ant_nb);
}
void	parse(t_lem* map)
{
	char *line;

	line = NULL;
	parse_ant(map);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
			check_start_end(line, map);
		ft_lstpush(&map->begin, line, ft_strlen(line) + 1);	
	}
}

int main(int argc, char **argv)
{
	t_lem	*map;
		
	argv[0] = 0;
	map = (t_lem*)ft_memalloc(sizeof(t_lem));
	map->begin = NULL;
	if (argc != 1)
	{
		ft_putstr("usage : ./lem-in < [map_file]\n");
		return (0);
	}
	parse(map);
	if (!map->begin)
	{
		
	}
	while (map->begin)
	{
		ft_putendl((map->begin)->content);
		map->begin = (map->begin)->next;
	}
	return (0);
}
