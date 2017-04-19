/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 01:24:54 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/12 02:05:35 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	**color_tab_init(char **color_tab)
{
	color_tab[0] = "{red}";
	color_tab[1] = "{grn}";
	color_tab[2] = "{yel}";
	color_tab[3] = "{blu}";
	color_tab[4] = "{mag}";
	color_tab[5] = "{cyn}";
	color_tab[6] = "{wht}";
	color_tab[7] = "{ec}";
	return (color_tab);
}

static char	*ft_putcolor(char *temp_c, int i)
{
	if (i == 0)
		ft_strncpy(temp_c, RED, 5);
	else if (i == 1)
		ft_strncpy(temp_c, GRN, 5);
	else if (i == 2)
		ft_strncpy(temp_c, YEL, 5);
	else if (i == 3)
		ft_strncpy(temp_c, BLU, 5);
	else if (i == 4)
		ft_strncpy(temp_c, MAG, 5);
	else if (i == 5)
		ft_strncpy(temp_c, CYN, 5);
	else if (i == 6)
		ft_strncpy(temp_c, WHT, 5);
	else if (i == 7)
		ft_strncpy(temp_c, EC, 4);
	if (temp_c + 5 && i != 7)
		return (temp_c + 5);
	else if (temp_c + 4 && i == 7)
		return (temp_c + 4);
	return (NULL);
}

static void	ft_search_color(char *s, t_flags *flags, char **color_tab)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (ft_strstr(s, color_tab[i]))
		{
			if (!flags->raw || ft_strstr(s, color_tab[i]) < flags->raw)
			{
				flags->l = i;
				flags->raw = ft_strstr(s, color_tab[i]);
			}
			if (i == 7)
			{
				if ((flags->raw = ft_putcolor(flags->raw, flags->l)))
					s = flags->raw;
				else
					return ;
				flags->raw = NULL;
				i = 0;
				flags->l = 0;
			}
		}
		i++;
	}
}

void		ft_control_color(char *s, t_flags *flags)
{
	char	*color_tab[7];

	flags->copy = 0;
	if (!ft_strchr(s, '{'))
	{
		flags->s = s;
		return ;
	}
	flags->copy = 1;
	flags->s = ft_strdup(s);
	flags->save = flags->s;
	color_tab_init(color_tab);
	ft_search_color(flags->s, flags, color_tab);
}
