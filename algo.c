/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 22:04:10 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/15 13:29:35 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

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
	find_ways(s, get_s(s), 0);
	i = -1;
	while (++i < s->ch_cnt)
	{
		j = -1;
		while (++j < s->ch_a[i]->length)
			printf("|%d|->", s->ch_a[i]->chain[j]);
		printf("\n");
	}
}
