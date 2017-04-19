/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 22:36:01 by agiulian          #+#    #+#             */
/*   Updated: 2016/09/20 22:49:38 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*lst;

	while (*alst)
	{
		lst = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = lst;
	}
	*alst = NULL;
}
