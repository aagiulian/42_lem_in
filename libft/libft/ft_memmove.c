/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 22:29:33 by agiulian          #+#    #+#             */
/*   Updated: 2016/09/18 19:08:01 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_c;
	const char	*src_c;
	size_t		i;

	i = 0;
	dst_c = (char*)dst;
	src_c = (const char*)src;
	if (dst_c > src_c)
	{
		while (len--)
			dst_c[len] = src_c[len];
	}
	else
	{
		while (i < len)
		{
			dst_c[i] = src_c[i];
			i++;
		}
	}
	return (dst);
}
