/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:08:37 by agiulian          #+#    #+#             */
/*   Updated: 2017/05/01 17:14:56 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_clist *ft_clstnew(void *content, int content_size)
{
	t_clist *clst;

	if (!(clst = (t_clist*)malloc(sizeof(t_clist))))
		return (NULL);
	if (content == NULL)
	{
		clst->content = NULL;
		clst->content_size = 0;
		clst->previous = NULL;
		clst->next = NULL;
	}
	else
	{
		if (!(clst->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(clst->content, content, content_size);
		clst->content_size = content_size;
		clst->previous = NULL;
		clst->next = NULL;
	}
	return (clst);
}
