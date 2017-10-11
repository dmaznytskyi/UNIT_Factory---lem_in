/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:17:47 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/11 16:59:10 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft/libft.h"
# include <stdio.h>///////////////

typedef struct	s_r
{
	char	*name;		//room name
	int		x;			//room x coordinate
	int		y;			//room y coordinate
	char	s;			//is start room
	char	e;			//is end room
	int		nr;			//room number
}				t_r;

typedef struct	s_l		//like linked lists, but...
{
	struct s_r	*room;
	struct s_l	*next;
}				t_l;

typedef struct	s_lem
{
	char		*input;		//all data to print
	struct s_l	*r;			//linked list of rooms
	char		**c;		//1-0 array of connection
	int			nr;			//number of rooms
	int			an;			//number of ants
	char		hs;			//have start
	char		he;			//have end
}				t_lem;

void	init(t_lem *s);
void	reader_l(t_lem *s);
void	destroy(t_lem *s);
void	print_error(char *text);
void	num_check(char *s, char *error);
void	new_room(t_lem *s, char *n, int x, int y);
void	add_input(t_lem *s, char *line);
void	enumerate(t_lem *s);
int		lgnl(char **line, int st);
int		split_cnt(char **s);
int		ch_r_name(t_lem *s, char *name);
int		ch_r_coord(t_lem *s, int x, int y);


void	rlstadd(t_l **head, t_l *new);
t_l		*rlstnew(t_r *room);

#endif
