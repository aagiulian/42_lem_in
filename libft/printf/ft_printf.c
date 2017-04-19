/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:35:04 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/10 11:55:21 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_free_stuff(char **buf, t_flags *flags)
{
	ft_strdel(buf);
	if (flags->copy == 1)
		ft_strdel(&flags->save);
	free(flags);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char	*buf;
	void	(*ptr_tab[128])(t_flags*);
	int		ret;
	t_flags	*flags;

	if ((ft_strlen(format) == 0) || (ft_strlen(format) == 1 && \
				format[0] == '%'))
		return (0);
	if (!(flags = (t_flags*)malloc(sizeof(t_flags))))
		return (-1);
	ft_init_fctptr_table(ptr_tab);
	flags->ret = 0;
	va_start(ap, format);
	ft_control_color((char*)format, flags);
	buf = ft_strparse(flags->s, &ap, ptr_tab, flags);
	if (flags->ret > 0)
		write(1, buf, flags->ret);
	ret = flags->ret;
	ft_free_stuff(&buf, flags);
	va_end(ap);
	return (ret);
}
