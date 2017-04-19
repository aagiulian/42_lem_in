/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:55:47 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/10 19:21:02 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_sign(t_flags *flags)
{
	if (flags->sign == 2)
	{
		(flags->edited)[flags->index] = '-';
		flags->sign = -1;
	}
	else if (flags->sign == 1)
	{
		(flags->edited)[flags->index] = '+';
		flags->sign = 0;
	}
	flags->index++;
	flags->sign_put = 1;
	flags->width--;
}

void	ft_put_space(t_flags *flags)
{
	flags->edited[flags->index] = ' ';
	flags->index++;
	if (flags->width)
		flags->width--;
	flags->space = -1;
}

void	ft_fill_width(t_flags *flags)
{
	if (flags->zero_padding)
		(flags->edited)[flags->index] = '0';
	else
		(flags->edited)[flags->index] = ' ';
	flags->index++;
	flags->width--;
}

void	ft_set_hashtag(t_flags *flags)
{
	if (flags->conversion == 'x' || flags->conversion == 'X' || \
			flags->conversion == 'p')
	{
		flags->edited[flags->index] = '0';
		flags->edited[flags->index + 1] = (flags->conversion == \
				'X') ? 'X' : 'x';
		flags->index += 2;
	}
}

void	ft_set_width(t_flags *flags)
{
	if (flags->conversion == 'p' && flags->zero_padding)
	{
		ft_set_hashtag(flags);
		flags->alternate_form = 0;
	}
	if (flags->sign == 0)
	{
		while (flags->width > flags->raw_len && flags->width > flags->precision)
			ft_fill_width(flags);
	}
	if (flags->sign)
	{
		while (flags->width - 1 + flags->sign_put > flags->raw_len && \
				flags->width - 1 + flags->sign_put > flags->precision)
			ft_fill_width(flags);
	}
}
