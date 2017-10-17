/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:04:34 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/17 21:05:52 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	destroy(t_lem *s)
{
	int i;
   
	i = -1;
	while (s->r)
	{
		ft_strdel(&s->r->room->name);
		s->r = s->r->next;
	}
	free(s->r);
	while (++i < s->ch_cnt)
		free(s->ch_a[i]->chain);
	free(s->ch_a);
	ft_strdel(&s->input);
	ft_strdel(&s->tmp);
	free(s->vis);
	i = -1;
	while (++i < s->dim)
		free(s->c[i]);
	free(s->c);
}
