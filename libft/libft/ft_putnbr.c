/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 17:27:41 by agiulian          #+#    #+#             */
/*   Updated: 2016/09/14 17:51:33 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int				size;
	unsigned int	save1;
	unsigned int	save2;

	size = 1;
	if (n < 0)
	{
		ft_putchar('-');
		save1 = -n;
	}
	else
		save1 = n;
	save2 = save1;
	while ((save2 /= 10) > 0)
		size *= 10;
	while (size != 0)
	{
		ft_putchar((save1 / size) + '0');
		save1 = save1 % size;
		size /= 10;
	}
}
