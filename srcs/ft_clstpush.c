/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:04:39 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/08 16:38:41 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_clstpush(t_clist **begin_list, void *content, size_t content_size)
{
	t_clist *clst;

	clst = *begin_list;
	if (clst)
	{
		while (clst->next)
			clst = clst->next;
		clst->next = ft_clstnew(content, content_size);
		clst->next->previous = clst;
	}
	else
		*begin_list = ft_clstnew(content, content_size);
}
