/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:43:17 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/21 12:49:25 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **begin_list)
{
	t_list	*lst;

	if (*begin_list)
	{
		lst = *begin_list;
		*begin_list = (*begin_list)->next;
		return (lst);
	}
	else
		return (NULL);
}
