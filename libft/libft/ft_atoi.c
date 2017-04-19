/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:19:18 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/05 18:14:39 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int result;
	int negative;

	i = 0;
	negative = 0;
	result = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-result);
	return (result);
}
