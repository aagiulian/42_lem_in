/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:13:57 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 17:43:41 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_patch(t_flags *flags)
{
	if (!(flags->conversion == 'c' || flags->conversion == 'C' || \
				flags->conversion == 'S'))
		flags->raw_len = ft_strlen(flags->raw);
	if (flags->conversion == 'p' && flags->precise && flags->raw[0] == '0')
		flags->raw_len = 0;
	if ((flags->conversion == 'x' || flags->conversion == 'X' || \
				flags->conversion == 'p') && flags->alternate_form)
		flags->raw_len += 2;
	if (flags->conversion == 'c' || flags->conversion == 'C')
		flags->precision = 0;
	if (flags->conversion == 's' || flags->conversion == 'S')
	{
		if (flags->raw_len == 0 || (flags->precision >= flags->raw_len))
		{
			flags->precise = 0;
			flags->precision = 0;
		}
		if (flags->precise && flags->raw_len)
		{
			ft_bzero(flags->raw + flags->precision, flags->raw_len - \
					flags->precision);
			flags->raw_len = ft_strlen(flags->raw);
		}
	}
}

void	ft_zero_priority(t_flags *flags)
{
	char	*list;

	list = "diobBuxX";
	if (flags->zero_padding && flags->left_adjusting)
		flags->zero_padding = 0;
	if (ft_strchr(list, flags->conversion))
	{
		if (flags->precision)
			flags->zero_padding = 0;
		else if (flags->zero_padding)
		{
			flags->precision = flags->width;
			if (flags->conversion == 'x' && flags->alternate_form)
				flags->alternate_form = 2;
			if (flags->precision && (flags->sign || flags->space))
				flags->precision--;
		}
	}
}

void	ft_size_priority(t_flags *flags)
{
	char	*list;

	list = "dioObBuxX";
	if (flags->conversion == '%')
		flags->precision = 0;
	if (ft_strchr(list, flags->conversion))
	{
		if (flags->raw_len >= flags->width)
			flags->width = 0;
		if (flags->sign == 2)
			flags->raw_len--;
		if (flags->precise && flags->raw_len == 1 && flags->raw[0] == \
				'0')
		{
			flags->raw_len = 0;
			flags->raw = "";
		}
	}
	if (flags->precision >= flags->width || flags->raw_len >= \
			flags->width)
		flags->width = 0;
}

void	ft_signed_priority(t_flags *flags)
{
	char	*list;

	list = "aAdDeEfFgGi";
	if (flags->raw && (flags->raw)[0] == '-')
		flags->sign = 2;
	if ((flags->space > 0) && (flags->sign || !ft_strchr(list, \
					flags->conversion)))
		flags->space = 0;
	if ((flags->sign > 0) && (!ft_strchr(list, flags->conversion)))
		flags->sign = 0;
}

void	ft_length_priority(t_flags *flags)
{
	char	*list;
	char	*list2;
	char	*list3;

	list = "dinobux";
	list2 = "cs";
	list3 = "DBOUCS";
	if (!ft_strchr(list, flags->conversion))
	{
		flags->h = 0;
		flags->j = 0;
		flags->z = 0;
		if (!(flags->l == 1 && ft_strchr(list2, flags->conversion)))
			flags->l = 0;
	}
	if (ft_strchr(list3, flags->conversion))
	{
		flags->l = 1;
		flags->conversion += 32;
	}
}
