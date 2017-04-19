/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 00:35:07 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/20 14:21:46 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*init_fd(int fd)
{
	t_fd	*new;

	new = malloc(sizeof(t_fd));
	new->fd = fd;
	new->stc = NULL;
	return (new);
}

t_fd	*lstpush_or_modify(t_list **begin, int fd)
{
	t_list	*lst;
	t_fd	*new;

	lst = *begin;
	while (lst)
	{
		if (((t_fd*)(lst->content))->fd == fd)
			return ((t_fd*)(lst->content));
		if (lst->next == NULL)
		{
			new = init_fd(fd);
			lst->next = ft_lstnew(new, sizeof(t_fd));
			free(new);
			return ((t_fd*)(lst->next->content));
		}
		lst = lst->next;
	}
	new = init_fd(fd);
	*begin = ft_lstnew(new, sizeof(t_fd));
	free(new);
	return ((t_fd*)((*begin)->content));
}

int		ft_checkstc(t_list **begin, char **line, int fd)
{
	char	*tmp;
	int		i;
	t_fd	*ptr;

	if ((ptr = lstpush_or_modify(begin, fd)) && ptr->stc \
			&& ft_strchr((ptr->stc), '\n'))
	{
		i = ft_strchr(ptr->stc, '\n') - ptr->stc;
		*line = ft_strndup(ptr->stc, i);
		tmp = ft_strdup(ptr->stc);
		free(ptr->stc);
		ptr->stc = ft_strdup(tmp + i + 1);
		ft_strdel(&tmp);
		return (1);
	}
	else if (ptr->stc)
	{
		*line = ft_strdup(ptr->stc);
		ft_strdel(&(ptr->stc));
	}
	return (0);
}

int		ft_read(int fd, t_list **begin, char **line)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	t_fd	*ptr;

	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(ft_strchr(buf, '\n')))
			*line = ft_strjoin(*line, buf);
		else
		{
			*line = ft_strnjoin(*line, buf, (ft_strchr(buf, '\n') - buf));
			ptr = lstpush_or_modify(begin, fd);
			ptr->stc = ft_strdup(buf + (ft_strchr(buf, '\n') - buf) + 1);
			return (1);
		}
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*begin = NULL;
	int				ret;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	if (ft_checkstc(&begin, line, fd))
		return (1);
	ret = ft_read(fd, &begin, line);
	if (ret == 1 || ret == -1)
		return (ret);
	if (*line == NULL || (ft_strlen(*line) == 0))
		return (0);
	return (1);
}
