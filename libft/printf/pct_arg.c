/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:41:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/06 20:48:44 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pct_conversion(t_flags *flags)
{
	flags->raw = (char*)malloc(2);
	if (!flags->raw)
		return ;
	flags->raw[0] = '%';
	flags->raw[1] = '\0';
}

void		ft_pct_arg(t_flags *flags)
{
	ft_pct_conversion(flags);
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
