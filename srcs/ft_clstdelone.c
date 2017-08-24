/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:13:09 by agiulian          #+#    #+#             */
/*   Updated: 2017/05/01 17:14:32 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void ft_clstdelone(t_clist **alst)//, void (*del)(void*, size_t))
{
	//	del(*clst, (*clst)->content_size);
	if ((*alst)->previous)
		(*alst)->previous->next = (*alst)->next;
	if ((*alst)->next)
		(*alst)->next->previous = (*alst)->previous;
	*alst = NULL;
}
