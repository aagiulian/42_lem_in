/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xcapint_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 17:23:48 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_xcapint_conversion(t_flags *flags)
{
	if (!flags->h && !flags->l && !flags->j && !flags->j && !flags->z)
		flags->raw = ft_uitoabase_cap(va_arg(*(flags->ap), unsigned int), 16);
	else if (flags->h == 2)
		flags->raw = ft_uitoabase_cap((unsigned char)va_arg(*(flags->ap), \
					unsigned int), 16);
	else if (flags->h == 1)
		flags->raw = ft_uitoabase_cap((unsigned short)va_arg(*(flags->ap), \
					unsigned int), 16);
	else if (flags->l == 1)
		flags->raw = ft_uitoabase_cap((unsigned long)va_arg(*(flags->ap), \
					unsigned long int), 16);
	else if (flags->l == 2)
		flags->raw = ft_uitoabase_cap(va_arg(*(flags->ap), unsigned \
					long long), 16);
	else if (flags->j == 1)
		flags->raw = ft_uitoabase_cap((uintmax_t)va_arg(*(flags->ap), \
					uintmax_t), 16);
	else if (flags->z == 1)
		flags->raw = ft_uitoabase_cap(va_arg(*(flags->ap), size_t), 16);
}

void		ft_xcapint_arg(t_flags *flags)
{
	ft_xcapint_conversion(flags);
	if (!(ft_strcmp(flags->raw, "0")))
		flags->alternate_form = 0;
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
