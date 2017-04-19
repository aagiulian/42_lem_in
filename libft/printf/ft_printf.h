/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:31:06 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/10 11:52:53 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <inttypes.h>

# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define EC "\x1B[0m"

typedef struct	s_flags
{
	va_list		*ap;
	int			left_adjusting;
	int			sign;
	int			sign_put;
	int			space;
	int			alternate_form;
	int			width;
	int			zero_padding;
	int			precision;
	int			precise;
	int			h;
	int			l;
	int			j;
	int			z;
	char		conversion;
	char		*raw;
	int			raw_len;
	int			malloc_len;
	char		*edited;
	int			index;
	int			ret;
	char		*save;
	char		*s;
	int			copy;
}				t_flags;

int				ft_printf(const char *restrict format, ...);
char			*ft_strparse(char *s, va_list *ap, void (**ptr_tab)(t_flags*),\
		t_flags *flags);
char			*ft_grep_all(char *s, t_flags *flags, va_list *ap);
char			*ft_grep_flags(char *s, t_flags *flags);
char			*ft_grep_width(char *s, t_flags *flags);
char			*ft_grep_precision(char *s, t_flags *flags);
char			*ft_grep_length(char *s, t_flags *flags);
char			*ft_grep_conversion(char *s, t_flags *flags);
void			ft_reset_struct(t_flags *flags, va_list *ap);
void			ft_set_priority(t_flags *flags);
void			ft_patch(t_flags *flags);
void			ft_zero_priority(t_flags *flags);
void			ft_left_over_zero(t_flags *flags);
void			ft_length_priority(t_flags *flags);
void			ft_signed_priority(t_flags *flags);
void			ft_size_priority(t_flags *flags);
void			ft_init_fctptr_table(void (**ptr_tab)(t_flags*));
void			ft_char_arg(t_flags *flags);
void			ft_int_arg(t_flags *flags);
void			ft_uint_arg(t_flags *flags);
void			ft_bint_arg(t_flags *flags);
void			ft_oint_arg(t_flags *flags);
void			ft_str_arg(t_flags *flags);
void			ft_xint_arg(t_flags *flags);
void			ft_xcapint_arg(t_flags *flags);
void			ft_pct_arg(t_flags *flags);
int				ft_malloc_len(t_flags *flags);
void			ft_put_sign(t_flags *flags);
void			ft_put_space(t_flags *flags);
void			ft_fill_width(t_flags *flags);
char			*ft_edit_width(char	*s, t_flags *flags);
void			ft_set_hashtag(t_flags *flags);
void			ft_set_width(t_flags *flags);
void			ft_edit_raw(t_flags *flags);
void			ft_edit_raw_left(t_flags *flags);
char			*ft_memjoin(char const *s1, char const *s2, unsigned int n1);
char			*ft_memnjoin(char const *s1, char const *s2, unsigned int n1, \
		unsigned int n2);
void			ft_handle_unicode(t_flags *flags, unsigned long long i);
void			ft_handle_unicode_char(t_flags *flags, unsigned long long i);
void			ft_double_octet(t_flags *flags, unsigned long long i);
void			ft_triple_octet(t_flags *flags, unsigned long long i);
void			ft_quad_octet(t_flags *flags, unsigned long long i);
void			ft_control_color(char *format, t_flags *flags);

#endif
