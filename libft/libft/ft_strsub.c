/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 17:49:39 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/08 16:52:50 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s_n;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	s_n = ft_strnew(len);
	if (s_n == NULL)
		return (NULL);
	while (i < len)
	{
		s_n[i] = s[i + start];
		i++;
	}
	s_n[i] = '\0';
	return (s_n);
}
