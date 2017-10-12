/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:37:22 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/12 17:56:47 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	init_links(t_lem *s)
{
	int	i;
	int	j;

	i = -1;
	s->c = (int**)malloc(sizeof(int*) * s->dim);
	while (++i < s->dim)
	{
		s->c[i] = (int*)malloc(sizeof(int) * s->dim);
		j = -1;
		while (++j < s->dim)
			s->c[i][j] = 0;
	}
	s->c[s->dim] = NULL;
}

void	init(t_lem *s)
{
	s->nr = 0;
	s->an = -1;
	s->hs = 0;
	s->he = 0;
	s->rl = 0;
	s->tmp = NULL;
	s->input = NULL;
}
