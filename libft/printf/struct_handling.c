/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:57:44 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 14:30:14 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_struct(t_flags *flags, va_list *ap)
{
	flags->ap = ap;
	flags->left_adjusting = 0;
	flags->sign = 0;
	flags->sign_put = 0;
	flags->space = 0;
	flags->alternate_form = 0;
	flags->width = 0;
	flags->zero_padding = 0;
	flags->precise = 0;
	flags->precision = 0;
	flags->h = 0;
	flags->l = 0;
	flags->j = 0;
	flags->z = 0;
	flags->conversion = '0';
	flags->raw = NULL;
	flags->raw_len = 0;
	flags->malloc_len = 0;
	flags->edited = NULL;
	flags->index = 0;
}
