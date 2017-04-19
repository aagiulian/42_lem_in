/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:15:25 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/07 17:37:36 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE 1024
# include <fcntl.h>
# include "libft.h"

typedef	struct	s_fd
{
	int			fd;
	char		*stc;
}				t_fd;
int				get_next_line(const int fd, char **line);

#endif
