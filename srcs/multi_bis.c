/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:28:11 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/13 17:37:03 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			update_room(t_lem *map)
{
	t_list	*begin;
	t_room	*room;

	begin = map->way;
	while (map->way)
	{
		room = map->way->content;
		while (room)
		{
			room->nb = room->to_move;
			room->to_move = 0;
			room = room->next;
		}
		map->way = map->way->next;
	}
	map->way = begin;
}

static void		put_ant(t_lem *map)
{
	t_list	*begin;
	t_room	*room;

	begin = map->way;
	while (map->way && map->ant_in < map->ant_nb)
	{
		room = map->way->content;
		room->nb = map->ant_in++ + 1;
		map->way = map->way->next;
	}
	map->way = begin;
}

static int		print_ant(t_room *room, int ant_out)
{
	int		save;

	while (room)
	{
		if (room->nb)
		{
			save = room->nb;
			ft_printf("L%i-%s ", save, room->name);
			room = room->next;
			if (room)
				room->to_move = save;
			else
				ant_out++;
		}
		else
			room = room->next;
	}
	return (ant_out);
}

int				init_multi(t_lem *map)
{
	t_list	*begin;
	t_room	*room;
	int		ant_out;

	begin = map->way;
	ant_out = 0;
	put_ant(map);
	while (map->way)
	{
		room = map->way->content;
		ant_out = print_ant(room, ant_out);
		map->way = map->way->next;
	}
	map->way = begin;
	return (ant_out);
}

void			free_way(void *way, size_t size)
{
	t_room *room;
	t_room *save;
	char	*str;

	(void)size;
	room = ((t_list*)way)->content;
	while (room)
	{
		save = room->next;
		str = room->name;
		ft_strdel(&str);
		free(room);
		room = save;
	}
	free(way);
	room = NULL;
	save = NULL;
}
