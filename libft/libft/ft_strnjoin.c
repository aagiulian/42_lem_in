/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:18:12 by agiulian          #+#    #+#             */
/*   Updated: 2016/12/06 17:58:41 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, unsigned int n)
{
	char			*s_n;
	unsigned int	ij[2];
	unsigned int	k;

	k = 0;
	if (!s1)
		return (ft_strndup(s2, n));
	ij[0] = 0;
	ij[1] = 0;
	s_n = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s_n == NULL)
		return (NULL);
	while (s1[k])
	{
		s_n[ij[0]++] = s1[k];
		k++;
	}
	while (*s2 && ij[1] < n)
	{
		s_n[ij[0]++] = *s2++;
		ij[1]++;
	}
	s_n[ij[0]] = '\0';
	free((char*)s1);
	return (s_n);
}
