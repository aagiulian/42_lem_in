/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 20:52:44 by agiulian          #+#    #+#             */
/*   Updated: 2016/09/18 21:38:10 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int i;
	unsigned int j;
	unsigned int lenlit;

	j = 0;
	lenlit = ft_strlen(little);
	if (lenlit == 0)
		return ((char*)big);
	while (big[j] && j < len)
	{
		i = 0;
		while ((big[j + i] == little[i]) && j + i < len)
		{
			if (i == lenlit - 1)
				return (char*)(big + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
