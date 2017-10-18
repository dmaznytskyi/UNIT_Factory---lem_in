/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:17:47 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/18 19:20:41 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft/libft.h"
# include <stdio.h>///////////////

# define LEAK system("leaks $(echo $(ps | grep lem-in | cut -d ' ' -f 1) | cut -d ' ' -f 2) && leaks $(echo $(ps | grep lem-in | cut -d ' ' -f 1) | cut -d ' ' -f 1)");

typedef struct	s_r
{
	char	*name;		//room name
	int		x;			//room x coordinate
	int		y;			//room y coordinate
	int		s;			//is start room
	int		e;			//is end room
	int		nr;			//room number
}				t_r;

typedef struct	s_ch	//chain connection structure
{
	int	*chain;
	int	length;
	int end;
}				t_ch;

typedef struct	s_l		//like linked lists, but...
{
	struct s_r	*room;
	struct s_l	*next;
}				t_l;

typedef struct	s_lem
{
	char		*input;		//all data to print
	struct s_l	*r;			//linked list of rooms
	struct s_ch	**ch_a;		//array of chains
	int			ch_cnt;		//total amount of chains
	int			**c;		//1-0 array of connection
	int			dim;		//dimension of link arr
	int			nr;			//number of rooms
	int			an;			//number of ants
	int			hs;			//have start
	int			he;			//have end
	int			rl;			//room entry lock
	int			*vis;		//visited rooms
	char		*tmp;
}				t_lem;

void			init(t_lem *s);
void			init_links(t_lem *s);
void			algo(t_lem *s);
void			reader_l(t_lem *s);
void			destroy(t_lem *s);
void			print_error(char *text);
void			num_check(char *s, char *error);
void			new_room(t_lem *s, char *n, int x, int y);
void			add_input(t_lem *s, char *line);
void			enumerate(t_lem *s);

void			find_ways(t_lem *s, int st);

int				split_cnt(char **s);
int				ch_r_name(t_lem *s, char *name);
int				ch_r_coord(t_lem *s, int x, int y);
int				ch_l_avail(t_lem *s);
int				se_link(t_lem *s, char what);
int				get_nr(t_lem *s, char *n);
int				get_s(t_lem *s);
int				get_e(t_lem *s);

char			*get_name(t_lem *s, int nr);

void			rlstadd(t_l **head, t_l *new);
t_l				*rlstnew(t_r *room);

#endif
