/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:43:18 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/10 11:54:48 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_grep_all(char *s, t_flags *flags, va_list *ap)
{
	ft_reset_struct(flags, ap);
	s = ft_grep_flags(s, flags);
	s = ft_grep_width(s, flags);
	s = ft_grep_precision(s, flags);
	s = ft_grep_length(s, flags);
	s = ft_grep_conversion(s, flags);
	return (s);
}

int		ft_maxtwo(int a, int b)
{
	if (b > a)
		return (b);
	else
		return (a);
}

int		ft_malloc_len(t_flags *flags)
{
	int max;
	int	sign;

	sign = flags->sign;
	if (sign == 2)
		sign = 1;
	max = ft_maxtwo(flags->width, flags->precision);
	if (max >= flags->raw_len)
	{
		if (max == flags->precision)
		{
			if (flags->conversion == 'p' || (flags->conversion == 'x' \
						&& flags->alternate_form == 1))
			{
				flags->raw_len -= 2;
				return (max + 2);
			}
			return (max + sign + flags->space);
		}
		else
			return (max);
	}
	else
		return ((flags->raw_len) + sign + flags->space);
}

char	*ft_edit_width(char *s, t_flags *flags)
{
	while (*s >= '0' && *s <= '9')
	{
		flags->width *= 10;
		flags->width += *s - '0';
		s++;
	}
	return (s);
}
