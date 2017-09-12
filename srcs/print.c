/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 08:57:19 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/12 14:46:19 by agiulian         ###   ########.fr       */
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

void	print_all(t_lem *map)
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
