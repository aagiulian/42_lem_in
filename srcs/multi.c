/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:36:50 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/13 17:11:25 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*create_room(char *name)
{
	t_room	*room;

	if (!(room = malloc(sizeof(t_room))))
		exit(-1);
	if (!(room->name = ft_strdup(name)))
		exit(-1);
	room->nb = 0;
	room->to_move = 0;
	room->next = NULL;
	return (room);
}

static void		room_push(t_room **begin, char *name)
{
	t_room	*room;

	room = *begin;
	if (room)
	{
		while (room->next)
			room = room->next;
		room->next = create_room(name);
	}
	else
		*begin = create_room(name);
}

static t_room	*create_way(t_list *path)
{
	char	**tab;
	int		len;
	t_room	*room;

	room = NULL;
	tab = path->content;
	len = ft_tablen(tab) - 1;
	while (len >= 0)
	{
		room_push(&room, tab[len]);
		len--;
	}
	return (room);
}

void			create_path_room(t_lem *map)
{
	t_list	*begin;
	t_room	*room;

	map->way = NULL;
	begin = map->paths;
	while (map->paths)
	{
		room = create_way(map->paths);
		ft_lstpush(&map->way, room, sizeof(t_room));
		free(room);
		map->paths = map->paths->next;
	}
	map->paths = begin;
}
