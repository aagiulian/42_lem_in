/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 20:39:05 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/08 17:31:24 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	i = 0;
	j = 0;
	if (dst_len > size)
		return (size + ft_strlen(src));
	while (dst[i])
		i++;
	while (src[j] && (j + i + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst_len + ft_strlen(src));
}
