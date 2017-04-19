/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 20:27:07 by agiulian          #+#    #+#             */
/*   Updated: 2016/09/16 23:36:41 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_ptr;
	char	*src_ptr;

	dst_ptr = (char*)dst;
	src_ptr = (char*)src;
	while (n--)
		dst_ptr[n] = src_ptr[n];
	return (dst);
}
