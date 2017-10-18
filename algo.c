/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 22:04:10 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/18 19:54:47 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

char	*get_name(t_lem *s, int nr)
{
	t_l	*tmp;

	tmp = s->r;
	while (tmp)
	{
		if (nr == tmp->room->nr)
			return (tmp->room->name);
		tmp = tmp->next;
	}
	free(tmp);
	return (0);
}

void	algo(t_lem *s)
{
	ft_putchar('\n');
	int i = 0;
	int j = 0;
	find_ways(s, get_s(s));
	i = -1;
	while (++i < s->ch_cnt)
	{
		j = -1;
		while (++j < s->ch_a[i]->length && s->ch_a[i]->chain[j] != -1)
			printf("|%s|->", get_name(s, s->ch_a[i]->chain[j]));
		printf("\n");
	}
}
