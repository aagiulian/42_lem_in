/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 08:57:19 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/07 18:21:30 by agiulian         ###   ########.fr       */
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

void	move_ant(t_list *p, int i, int j, int k, t_lem *map)
{
	char **tab;

	ft_printf("\ni = %i\n", i);
	ft_printf("j = %i\n", j);
	ft_printf("k = %i\n", k);
	
	//if (!p)
	//	return ;
	tab = (char**)p->content;
	if (ft_tablen(tab) - i + j < 0)
		return ;
	ft_printf("L%i-%s", 1 + j + k, tab[ft_tablen(tab) - i + j]);
	if (k + 1 < i * map->mu && j + 1 < map->ant_nb)
		ft_putchar(' ');
}

void	multi_path(t_lem *map)
{
	int i;
	int	j;
	int	ant_in;
	t_list *p;
	int	k;
	char	**tab;

	tab = (char**)map->paths->content;
	ant_in = 0;
	i = 1;
	while (i < map->ant_nb + ft_tablen(map->paths->content))
	{
		p = map->paths;
		j = 0;
		if (i > ft_tablen(map->paths->content) * map->mu)
		{
			ant_in += map->mu;
			j = ant_in;
		}
		while (j < i * map->mu && j < map->ant_nb)
		{
			k = 0;
			if (j % map->mu == 0)
				p = map->paths;
			while (k < map->mu)
			{
				move_ant(p, i, j, k, map);
				p = p->next;
				k++;
			}
			j += k;
		//	ft_printf("\n-%i-\n", j);
		}
		ft_putendl("");
		i++;
	}
}
