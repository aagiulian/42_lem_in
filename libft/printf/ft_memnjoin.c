/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:18:12 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 14:23:03 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memnjoin(char *s1, char *s2, unsigned int n1, \
		unsigned int n2)
{
	char			*s_n;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
		return (ft_memcpy(ft_strnew(n2), s2, n2));
	i = 0;
	j = 0;
	s_n = ft_strnew(n1 + n2);
	if (s_n == NULL)
		return (NULL);
	while (i < n1)
	{
		s_n[i] = s1[i];
		i++;
	}
	while (j < n2)
	{
		s_n[i++] = *s2++;
		j++;
	}
	ft_strdel(&s1);
	s_n[i] = '\0';
	return (s_n);
}
