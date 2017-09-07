/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:33:40 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/07 19:59:15 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_path(void *path, size_t size)
{
	char 	*str;
	t_list	*lst;

	lst = (t_list*)path;
	str = (char*)(lst->content);
	(void)size;
	ft_strdel(&str);
	free(path);
}

void	free_all(t_lem *map)
{
	ft_lstdel(&map->paths, &free_path);
	ft_strdel(&(map->start_s));
	ft_strdel(&(map->end_s));
	ft_lstdel(&map->rooms, &free_path);
}
