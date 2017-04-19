/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 19:45:56 by agiulian          #+#    #+#             */
/*   Updated: 2016/09/17 19:53:30 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	unsigned int	i;
	char			*s_n;

	i = 0;
	s_n = ft_strnew(n);
	if (s_n == NULL)
		return (NULL);
	while (s1[i] && i < n)
	{
		s_n[i] = s1[i];
		i++;
	}
	s_n[i] = '\0';
	return (s_n);
}
