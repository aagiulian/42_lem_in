/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:49:39 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/10 11:54:16 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_edit_raw(t_flags *flags)
{
	if (flags->sign > 0 && flags->zero_padding)
		ft_put_sign(flags);
	if (flags->space)
		ft_put_space(flags);
	if (flags->width > 0)
		ft_set_width(flags);
	if (flags->alternate_form)
		ft_set_hashtag(flags);
	if (flags->sign > 0)
		ft_put_sign(flags);
	while (flags->precision > flags->raw_len)
	{
		(flags->edited)[flags->index] = '0';
		flags->precision--;
		flags->index++;
	}
	ft_memcpy(flags->edited + flags->index, flags->raw - flags->sign, \
			flags->raw_len);
	(flags->edited)[flags->malloc_len] = '\0';
}

void	ft_edit_raw_left(t_flags *flags)
{
	if (flags->sign > 0)
		ft_put_sign(flags);
	if (flags->space)
		ft_put_space(flags);
	if (flags->alternate_form)
		ft_set_hashtag(flags);
	while (flags->precision > flags->raw_len)
	{
		(flags->edited)[flags->index] = '0';
		flags->precision--;
		flags->index++;
	}
	ft_memcpy(flags->edited + flags->index, flags->raw - flags->sign, \
			flags->raw_len);
	flags->index += flags->raw_len;
	if ((flags->conversion == 'x' || flags->conversion == 'X' || \
				flags->conversion == 'p') && \
			flags->alternate_form)
		flags->index -= 2;
	if (flags->width > 0)
		ft_set_width(flags);
	(flags->edited)[flags->malloc_len] = '\0';
}
