/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 10:36:58 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/08 10:44:26 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_clstdel(t_clist **alst, void (*del)(void*, size_t))
{
	t_clist	*lst;

	while (*alst)
	{
		lst = (*alst)->next;
		ft_clstdelone(alst, del);
		*alst = lst;
	}
	*alst = NULL;
}
