/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:13:09 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/08 16:38:29 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_clstdelone(t_clist **alst, void (*del)(void*, size_t))
{
	if ((*alst)->previous)
		(*alst)->previous->next = (*alst)->next;
	if ((*alst)->next)
		(*alst)->next->previous = (*alst)->previous;
	del(*alst, (*alst)->content_size);
	*alst = NULL;
}
