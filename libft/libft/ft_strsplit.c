/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 19:42:05 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/08 18:01:12 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!s || !c || !(tab = (char**)malloc(sizeof(char*) * \
					(ft_countword(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] && s[i] != c)
			i++;
		if (k != i)
		{
			tab[j] = ft_strndup(s + k, i - k);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
