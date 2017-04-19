/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 17:32:00 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/08 16:50:23 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s_n;

	if (!s || !f)
		return (NULL);
	s_n = ft_strnew(ft_strlen(s));
	if (s_n == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_n[i] = f(i, s[i]);
		i++;
	}
	s_n[i] = '\0';
	return (s_n);
}
