/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 08:57:19 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/13 16:44:23 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_path(t_lem *map)
{
	int		i;
	int		j;
	char	**tab;

	map->ant_in = 0;
	i = 1;
	while (i < map->ant_nb + ft_tablen(map->paths->content))
	{
		j = 0;
		if (i > ft_tablen(map->paths->content))
		{
			map->ant_in++;
			j = map->ant_in;
		}
		while (j < i && j < map->ant_nb)
		{
			tab = (char**)map->paths->content;
			ft_printf("L%i-%s", 1 + j, tab[ft_tablen(tab) - i + j]);
			if (j + 1 < i && j + 1 < map->ant_nb)
				ft_putchar(' ');
			j++;
		}
		ft_putendl("");
		i++;
	}
}

void	print_map(t_lem *map)
{
	t_list *lst;

	ft_putnbr(map->ant_nb);
	ft_putendl("");
	lst = map->begin;
	while (map->begin)
	{
		ft_putendl((map->begin)->content);
		map->begin = (map->begin)->next;
	}
	map->begin = lst;
	ft_putendl("");
	print_path(map);
}

void	print_p_path(t_lem *map)
{
	t_list	*begin;
	char	**tab;
	int		i;

	begin = map->paths;
	ft_printf("This map has %i unique(s) path(s) available.\n\n", map->mu);
	while (map->mu)
	{
		tab = (char**)map->paths->content;
		i = ft_tablen(tab) - 1;
		ft_printf("[ %s ] =>", map->start_s);
		while (i >= 0)
		{
			ft_printf(" [ %s ]", tab[i]);
			if (i > 0)
				ft_printf(" =>");
			i--;
		}
		ft_putendl("");
		map->paths = map->paths->next;
		map->mu--;
	}
	map->paths = begin;
}

void	print_m_path(t_lem *map)
{
	int		i;
	t_list	*way;

	way = map->way;
	i = 0;
	while (i < map->ant_nb)
	{
		update_room(map);
		i += init_multi(map);
		ft_putendl("");
	}
}

void	print_all(t_lem *map)
{
	if (map->c_p)
		print_p_path(map);
	else if (map->c_m && map->mu > 1)
	{
		create_path_room(map);
		print_m_path(map);
	}
	else
		print_map(map);
}
