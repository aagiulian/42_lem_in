/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 08:57:19 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/06 19:59:20 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_path(t_lem *map)
{
	int i;
	int	j;
	int	ant_in;
	char	**tab;

	ant_in = 0;
	i = 1;
	while (i < map->ant_nb + ft_tablen(map->paths->content))
	{
		j = 0;
		if (i > ft_tablen(map->paths->content))
		{
			ant_in++;
			j = ant_in;
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

void	print_path_multi(t_lem *map)
{
	int i;
	int	j;
	int	k;
	int	ant_in;
	t_list *start;

	start = map->paths->content;

	ant_in = 0;
	i = 1;
	while (i < (map->ant_nb + ft_tablen(map->paths->content) / map->mu))
	{
		k = 0;
		j = 0;
		if (i > ft_tablen(map->paths->content))
		{
			ant_in + map->mu;
			j = ant_in;
		}
		while (j < i && j < map->ant_nb)
		{
			while (k < mu)
			{
			tab = (char**)map->paths->content;
			ft_printf("L%i-%s", 1 + j, tab[ft_tablen(tab) - i + j]);
			if (j + 1 < i && j + 1 < map->ant_nb)
				ft_putchar(' ');
			}
			j++;
		}
		ft_putendl("");
		i++;
	}
}
