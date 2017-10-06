/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:17:47 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/06 17:58:20 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft/libft.h"

typedef struct	s_l
{
	char	*r1;
	char	*r2;
}				t_l;

typedef struct	s_r
{
	char	*name;		//room name
	int		x;			//room x coordinate
	int		y;			//room y coordinate
}				t_r;

typedef struct	s_lem
{
	char		**input;	//all data to print
	struct s_l	*l;			//array of links
	struct s_r	*r;			//array of rooms
	int			nr;			//number of rooms
	int			an;			//number of ants
}				t_lem;

void	init(t_lem *s);
void	reader(t_lem *s);
void	destroy(t_lem *s);
void	print_error(char *text);
int		lgnl(char **line, int st);
int		split_cnt(char **s);

#endif
