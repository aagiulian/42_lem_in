/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 16:42:59 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/12 15:51:11 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_room(char *line, t_lem *map)
{
	char **tab;

	tab = ft_strsplit(line, ' ');
	if (tab[3] || !tab[0] || !tab[1] || !tab[2] || !ft_strisdigit(tab[1]) \
			|| !ft_strisdigit(tab[2]))
	{
		ft_tabdel(tab);
		return (-1);
	}
	if ((map->start == 1) || (map->end == 1))
	{
		if (map->c != map->save + 1)
			return (-1);
		else if (map->end == 1 && map->end++)
			map->end_s = ft_strdup(tab[0]);
		else if (map->start == 1 && map->start++)
			map->start_s = ft_strdup(tab[0]);
	}
	ft_lstpush(&map->rooms, tab[0], ft_strlen(tab[0]) + 1);
	ft_tabdel(tab);
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
		ft_tabdel(tab);
		return (-1);
	}
	else if (ft_strcmp(tab[0], tab[1]))
	{
		ft_clstpush(&map->tubes, line, ft_strlen(line) + 1);
		ft_tabdel(tab);
		return (0);
	}
	ft_tabdel(tab);
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

void	parse(t_lem *map)
{
	char *line;

	line = NULL;
	parse_ant(map);
	while (get_next_line(0, &line) > 0)
	{
		map->c++;
		if (ft_strlen(line) && line[0] != 'L' && line[0] != '#' && \
				ft_strstr(line, "-"))
			map->tube++;
		if (!ft_strlen(line) || line[0] == 'L' || (line[0] != '#' \
					&& map->tube && !ft_strstr(line, "-")))
			return ;
		if (line[0] == '#')
			check_start_end(map, line);
		if (store(line, map))
		{
			ft_strdel(&line);
			return ;
		}
		ft_lstpush(&map->begin, line, ft_strlen(line) + 1);
		free(line);
	}
	ft_strdel(&line);
}
