/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 15:57:01 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/07 19:25:04 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	parse_ant(t_lem* map)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	map->ant_nb = ft_atoi(line);
	ft_strdel(&line);
	if (!map->ant_nb)
	{
		ft_putendl("ERROR");
		exit(-1);
	}
}
