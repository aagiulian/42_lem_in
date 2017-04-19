/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 17:22:39 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_int_conversion(t_flags *flags)
{
	if (!flags->h && !flags->l && !flags->j && !flags->j && !flags->z)
		flags->raw = ft_itoabase(va_arg(*(flags->ap), int), 10);
	else if (flags->h == 2)
		flags->raw = ft_itoabase((signed char)va_arg(*(flags->ap), int), 10);
	else if (flags->h == 1)
		flags->raw = ft_itoabase((short)va_arg(*(flags->ap), int), 10);
	else if (flags->l == 1)
		flags->raw = ft_itoabase((long)va_arg(*(flags->ap), long), 10);
	else if (flags->l == 2)
		flags->raw = ft_itoabase((long long)va_arg(*(flags->ap), long long), \
				10);
	else if (flags->j == 1)
		flags->raw = ft_itoabase((intmax_t)va_arg(*(flags->ap), intmax_t), 10);
	else if (flags->z == 1)
		flags->raw = ft_itoabase((size_t)va_arg(*(flags->ap), size_t), 10);
}

void		ft_int_arg(t_flags *flags)
{
	ft_length_priority(flags);
	ft_int_conversion(flags);
	ft_set_priority(flags);
	flags->malloc_len = ft_malloc_len(flags);
	flags->edited = (char*)ft_strnew(flags->malloc_len);
	if (!flags->edited)
		return ;
	if (flags->left_adjusting)
		ft_edit_raw_left(flags);
	else
		ft_edit_raw(flags);
}
