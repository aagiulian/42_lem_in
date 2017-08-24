/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:45:17 by agiulian          #+#    #+#             */
/*   Updated: 2017/08/24 16:41:24 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft/includes/libft.h"
# include "../libft/libft/includes/get_next_line.h"
# include "../libft/printf/ft_printf.h"

typedef struct			s_tree
{
	char 				*content;
	struct s_tree		*parent;
	struct s_tree		*child;
	struct s_tree		*sibling;
	int					weight;
	struct s_tree		*parents;
	struct s_tree		*next;
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
void			check_start_end(t_lem *map, char *line);
int				check_room(t_lem *map, char *room1, char *room2);
void			parse_ant(t_lem *map);
void			parse(t_lem *map);

#endif
