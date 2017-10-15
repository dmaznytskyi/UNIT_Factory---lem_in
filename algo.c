/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 22:04:10 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/15 21:56:13 by dmaznyts         ###   ########.fr       */
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
	return (0);
}

void	algo(t_lem *s)
{
	ft_putchar('\n');
	int i = 0;
	int j = 0;
	while (i < s->dim)
	{
		j = 0;
		while (j < s->dim)
		{
			printf("%d ", s->c[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	find_ways(s, get_s(s), get_e(s), 0);
	i = -1;
	while (++i < s->ch_cnt)
	{
		j = -1;
		while (++j < s->ch_a[i]->length)
			printf("|%d|->", s->ch_a[i]->chain[j]);
		printf("\n");
	}
	j = 0;
	while (++i < s->an)
	{
		printf("L%d-%s\n", i, get_name(s, s->ch_a[0]->chain[++j]));
	}
}
