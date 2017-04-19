/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 17:27:41 by agiulian          #+#    #+#             */
/*   Updated: 2016/09/17 22:53:41 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				size;
	unsigned int	save1;
	unsigned int	save2;

	size = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		save1 = -n;
	}
	else
		save1 = n;
	save2 = save1;
	while ((save2 /= 10) > 0)
		size *= 10;
	while (size != 0)
	{
		ft_putchar_fd((save1 / size) + '0', fd);
		save1 = save1 % size;
		size /= 10;
	}
}
