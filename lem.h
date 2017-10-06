/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:17:47 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/06 14:06:09 by dmaznyts         ###   ########.fr       */
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
}				t_r;

typedef struct	s_lem
{
	struct s_r	*r;		//array of rooms
	int			nr;		//number of rooms
}				t_lem;

void	init(t_lem *s);
void	read(t_lem *s);
void	destroy(t_lem *s);

#endif
