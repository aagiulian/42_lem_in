/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 20:27:07 by agiulian          #+#    #+#             */
/*   Updated: 2016/09/17 21:53:30 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	i = 0;
	dst_ptr = (unsigned char*)dst;
	src_ptr = (const unsigned char*)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		if (src_ptr[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
