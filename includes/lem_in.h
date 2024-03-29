/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:45:17 by agiulian          #+#    #+#             */
/*   Updated: 2017/09/13 17:13:18 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft/includes/libft.h"
# include "../libft/libft/includes/get_next_line.h"
# include "../libft/printf/ft_printf.h"

typedef struct			s_wlist
{
	char				*content;
	struct s_wlist		*parent;
	struct s_wlist		*next;
	int					weight;
}						t_wlist;

typedef struct			s_clist
{
	char				*content;
	int					content_size;
	struct s_clist		*previous;
	struct s_clist		*next;
}						t_clist;

typedef struct			s_room
{
	char				*name;
	int					nb;
	int					to_move;
	struct s_room		*next;
}						t_room;

typedef struct			s_lem
{
	t_list				*begin;
	long long			ant_nb;
	long long			ant_in;
	int					start;
	int					end;
	int					tube;
	int					mu;
	int					c;
	int					c_p;
	int					c_m;
	int					save;
	char				*start_s;
	char				*end_s;
	t_clist				*tubes;
	t_list				*rooms;
	t_list				*paths;
	t_list				*way;
}						t_lem;

void					ft_clstdelone(t_clist **alst, void (*del)(void*, \
			size_t));
t_clist					*ft_clstnew(void *content, int content_size);
int						check_room(t_lem *map, char *room1, char *room2);
void					parse_ant(t_lem *map);
void					parse(t_lem *map);
void					print_path(t_lem *map);
void					multi_path(t_lem *map);
void					free_all(t_lem *map);
void					ft_clstdel(t_clist **alst, void (*del)(void*, size_t));
void					ft_clstpush(t_clist **begin_list, void *content, \
		size_t content_size);
void					free_tube(void *path, size_t size);
void					check_start_end(t_lem *map, char *line);
t_list					*ft_lstnewtube(void const *content);
void					ft_lstpushtube(t_list **begin_list, void *content);
void					free_wlist(t_wlist **alst);
void					make_list(t_lem *map, char *start);
int						only_one(char *name, t_wlist *starts);
void					print_all(t_lem *map);
void					create_path_room(t_lem *map);
int						init_multi(t_lem *map);
void					update_room(t_lem *map);
void					free_way(void *way, size_t size);

#endif
