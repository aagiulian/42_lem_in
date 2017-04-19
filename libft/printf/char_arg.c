/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/10 00:57:24 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_char_conversion(t_flags *flags)
{
	char				c;
	unsigned long long	i;

	flags->raw = ft_strnew(4);
	if (!flags->raw)
		return ;
	if (flags->l != 1)
		c = (va_arg(*(flags->ap), int));
	else
	{
		i = (va_arg(*(flags->ap), wchar_t));
		ft_handle_unicode_char(flags, i);
		return ;
	}
	flags->raw_len = 1;
	if (!c)
	{
		flags->precision = 0;
		flags->raw[0] = '\0';
	}
	else
		flags->raw[0] = c;
}

void		ft_char_arg(t_flags *flags)
{
	ft_length_priority(flags);
	ft_char_conversion(flags);
	if (flags->ret == -1)
	{
		ft_strdel(&flags->raw);
		return ;
	}
	ft_set_priority(flags);
	flags->malloc_len = ft_malloc_len(flags);
	flags->edited = ft_strnew(flags->malloc_len);
	if (!flags->edited)
		return ;
	if (flags->left_adjusting)
		ft_edit_raw_left(flags);
	else
		ft_edit_raw(flags);
}
