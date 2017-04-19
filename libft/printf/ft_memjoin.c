/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:18:12 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 14:40:29 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memjoin(char *s1, const char *s2, unsigned int n1)
{
	char			*s_n;
	unsigned int	i;

	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	s_n = ft_strnew(n1 + ft_strlen(s2));
	if (s_n == NULL)
		return (NULL);
	while (i < n1)
	{
		s_n[i] = s1[i];
		i++;
	}
	while (*s2)
		s_n[i++] = *s2++;
	ft_strdel(&s1);
	s_n[i] = '\0';
	return (s_n);
}
