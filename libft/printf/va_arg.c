/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:17:11 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 17:28:13 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_error(t_flags *flags)
{
	flags->raw = ft_strnew(1);
	flags->raw[0] = flags->conversion;
	ft_set_priority(flags);
	if (flags->width)
		flags->malloc_len = flags->width;
	else
		flags->malloc_len = 1;
	flags->edited = (char*)ft_strnew(flags->malloc_len);
	if (!flags->edited)
		return ;
	if (flags->left_adjusting)
		ft_edit_raw_left(flags);
	else
		ft_edit_raw(flags);
}

void	ft_init_fctptr_table(void (**ptr_tab)(t_flags*))
{
	int	i;

	i = 0;
	while (i < 128)
	{
		ptr_tab[i] = &ft_conv_error;
		i++;
	}
	ptr_tab[37] = &ft_pct_arg;
	ptr_tab[66] = &ft_bint_arg;
	ptr_tab[67] = &ft_char_arg;
	ptr_tab[68] = &ft_int_arg;
	ptr_tab[79] = &ft_oint_arg;
	ptr_tab[83] = &ft_str_arg;
	ptr_tab[85] = &ft_uint_arg;
	ptr_tab[88] = &ft_xcapint_arg;
	ptr_tab[98] = &ft_bint_arg;
	ptr_tab[99] = &ft_char_arg;
	ptr_tab[100] = &ft_int_arg;
	ptr_tab[105] = &ft_int_arg;
	ptr_tab[111] = &ft_oint_arg;
	ptr_tab[112] = &ft_xint_arg;
	ptr_tab[115] = &ft_str_arg;
	ptr_tab[117] = &ft_uint_arg;
	ptr_tab[120] = &ft_xint_arg;
}
