/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:18:12 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/27 15:14:15 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s_n;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (!s1)
		return (ft_strdup((char*)s2));
	s_n = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s_n == NULL)
		return (NULL);
	while (s1[j])
	{
		s_n[i++] = s1[j];
		j++;
	}
	while (*s2)
		s_n[i++] = *s2++;
	s_n[i] = '\0';
	free((char*)s1);
	return (s_n);
}
