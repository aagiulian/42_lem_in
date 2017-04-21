/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 20:52:44 by agiulian          #+#    #+#             */
/*   Updated: 2017/04/21 17:22:01 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int i;
	unsigned int j;
	unsigned int len;

	j = 0;
	len = ft_strlen(little);
	if (!big)
		return (NULL);
	if (len == 0)
		return ((char*)big);
	while (big[j])
	{
		i = 0;
		while (big[j + i] == little[i])
		{
			if (i == len - 1)
				return ((char*)big + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
