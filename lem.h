/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:17:47 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/10 16:37:01 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft/libft.h"

typedef struct	s_r
{
	char	*name;		//room name
	int		x;			//room x coordinate
	int		y;			//room y coordinate
	char	s;			//is start room
	char	e;			//is end room
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
	int			nr;			//number of rooms
	int			an;			//number of ants
}				t_lem;

void	init(t_lem *s);
void	reader(t_lem *s);
void	destroy(t_lem *s);
void	print_error(char *text);
void	num_check(char *s, char *error);
void	new_room(t_lem *s, char *n, int x, int y);
void	add_input(t_lem *s, char *line);
int		lgnl(char **line, int st);
int		split_cnt(char **s);

void	rlstadd(t_l **head, t_l *new);
t_l		*rlstnew(t_r *room);

#endif
