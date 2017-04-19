/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:50:37 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/10 11:40:56 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_set_priority(t_flags *flags)
{
	ft_patch(flags);
	ft_signed_priority(flags);
	ft_zero_priority(flags);
	ft_size_priority(flags);
}

static char	*ft_split(char *buf, t_flags *flags)
{
	buf = ft_memnjoin(buf, flags->edited, flags->ret, \
			flags->malloc_len);
	ft_strdel(&flags->edited);
	flags->ret += flags->malloc_len;
	return (buf);
}

static char	*ft_split_second(char **s, char *buf, t_flags *flags)
{
	buf = ft_memnjoin(buf, *s, flags->ret, ft_strchr(*s, '%') - *s);
	flags->ret += ft_strchr(*s, '%') - *s;
	*s = ft_strchr(*s, '%');
	return (buf);
}

static char	*ft_split_third(char *buf, t_flags *flags)
{
	if (flags->edited)
		buf = ft_split(buf, flags);
	if (flags->raw_len && flags->raw)
		ft_strdel(&flags->raw);
	return (buf);
}

char		*ft_strparse(char *s, va_list *ap, void (**ptr_tab)(t_flags*), \
		t_flags *flags)
{
	char	*buf;

	buf = NULL;
	while (*s)
	{
		if (*s && *s != '%' && ft_strchr(s, '%'))
			buf = ft_split_second(&s, buf, flags);
		else if (*s && *s != '%')
		{
			buf = ft_memjoin(buf, s, flags->ret);
			flags->ret += ft_strlen(s);
			return (buf);
		}
		s++;
		s = ft_grep_all(s, flags, ap);
		ptr_tab[(int)flags->conversion](flags);
		if (flags->ret == -1)
		{
			ft_strdel(&buf);
			return (NULL);
		}
		buf = ft_split_third(buf, flags);
	}
	return (buf);
}
