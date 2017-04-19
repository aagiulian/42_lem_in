/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:46:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/10 11:42:37 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_unicode_char(t_flags *flags, unsigned long long i)
{
	if (i > 128172 || (MB_CUR_MAX == 1 && i > 255))
	{
		flags->ret = -1;
		return ;
	}
	if (i == 0)
	{
		flags->precision = 0;
		flags->raw[0] = '\0';
		flags->raw_len = 1;
	}
	if (i < 128 || MB_CUR_MAX == 1)
	{
		flags->raw[0] = i;
		flags->raw_len = 1;
	}
	else if (i < 2048)
	{
		ft_double_octet(flags, i);
	}
	else if (i < 65536)
		ft_triple_octet(flags, i);
	else if (i >= 65536)
		ft_quad_octet(flags, i);
}

void	ft_handle_unicode(t_flags *flags, unsigned long long i)
{
	if (i > 128172)
	{
		flags->ret = -1;
		return ;
	}
	if (i == 0)
	{
		flags->precision = 0;
		flags->raw[0] = '\0';
		flags->raw_len = 1;
	}
	if (i < 128 || MB_CUR_MAX == 1)
	{
		flags->raw[0] = i;
		flags->raw_len = 1;
	}
	else if (i < 2048)
	{
		ft_double_octet(flags, i);
	}
	else if (i < 65536)
		ft_triple_octet(flags, i);
	else if (i >= 65536)
		ft_quad_octet(flags, i);
}

void	ft_double_octet(t_flags *flags, unsigned long long i)
{
	unsigned int unicode;

	unicode = 49280;
	unicode += (i >> 6) << 8;
	unicode += i & 63;
	flags->raw[0] = unicode >> 8;
	flags->raw[1] = unicode & 0xFF;
	flags->raw_len = 2;
}

void	ft_triple_octet(t_flags *flags, unsigned long long i)
{
	unsigned int unicode;
	unsigned int tampon;

	tampon = i;
	unicode = 14712960;
	unicode += (i >> 12) << 16;
	i = tampon;
	unicode += (i & 0xFC0) << 2;
	unicode += i & 0x3F;
	flags->raw[0] = unicode >> 16;
	flags->raw[1] = (unicode >> 8) & 0xFF;
	flags->raw[2] = unicode & 0xFF;
	flags->raw_len = 3;
}

void	ft_quad_octet(t_flags *flags, unsigned long long i)
{
	unsigned int unicode;
	unsigned int tampon;

	tampon = i;
	unicode = 4034953344;
	unicode += (i >> 18) << 24;
	i = tampon;
	unicode += (i & 0x3F000) << 4;
	i = tampon;
	unicode += (i & 0xFC0) << 2;
	unicode += i & 0x3F;
	flags->raw[0] = (unicode >> 24);
	flags->raw[1] = (unicode >> 16) & 0xFF;
	flags->raw[2] = (unicode >> 8) & 0xFF;
	flags->raw[3] = unicode & 0xFF;
	flags->raw_len = 4;
}
