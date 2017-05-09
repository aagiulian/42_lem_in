/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:45:17 by agiulian          #+#    #+#             */
/*   Updated: 2017/05/01 15:17:38 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft/includes/libft.h"
# include "libft/libft/includes/get_next_line.h"
# include "libft/printf/ft_printf.h"

typedef struct			s_tree
{
	char 				*content;
	struct s_tree		*parent;
	struct s_tree		*child;
	struct s_tree		*sibling;
}						t_tree;

typedef struct			s_clist
{
	char				*content;
	int					content_size;
	struct s_clist		*previous;
	struct s_clist		*next;
}						t_clist;

typedef struct	s_lem
{
	t_list		*begin;
	int			ant_nb;
	int			start;
	int			end;
	int			tube;
	char		*start_s;
	char		*end_s;
	t_clist		*tubes;
	t_list		*rooms;
	t_tree		*tree;
}				t_lem;

void 			ft_clstdelone(t_clist **alst);
t_clist 		*ft_clstnew(void *content, int content_size);
void			ft_clstpush(t_clist **begin_list, void *content, size_t content_size);

#endif
