/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:45:12 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/26 17:29:28 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_intsize(unsigned long long int i, int base)
{
	unsigned long long int size;

	size = 1;
	while (i / base > 0)
	{
		i /= base;
		size *= base;
	}
	return (size);
}
