/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 22:04:10 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/19 21:53:43 by dmaznyts         ###   ########.fr       */
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

void	print_ant(int nr, char *name)
{
	ft_putchar('L');
	ft_putnbr(nr + 1);
	ft_putchar('-');
	ft_putstr(name);
}

void	print_way(t_lem *s, int way)
{
	int		*tmp;
	int		i;
	int		j;
	t_ch	*ch;

	i = -1;
	ch = s->ch_a[way];
	tmp = (int*)malloc(sizeof(int) * s->an);
	while (++i < s->an)
		tmp[i] = -1;
	i = 0;
	while (++i < (s->an + s->ch_a[way]->length))
	{
		j = -1;
		while (++j < s->ch_a[way]->length)
		{

		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		if (get_name(s, s->ch_a[way]->chain[++j]))
		{
			if (i != 0)
				ft_putchar(' ');
		}
		else
		{
			ft_putchar('\n');
			j = -1;
		}
		if (tmp[i] != -1)
			print_ant(i, get_name(s, s->ch_a[way]->chain[j]));
	}
	free(tmp);
}

int		ch_sh_way(t_lem *s)
{
	int i;
	int	tl;
	int	tch;

	i = -1;
	tl = -1;
	tch = -1;
	while (++i < s->ch_cnt)
	{
		if (s->ch_a[i]->length > tl)
		{
			tl = s->ch_a[i]->length;
			tch = i;
		}
	}
	return (tch);
}

void	algo(t_lem *s)
{
	find_ways(s, get_s(s));
	if (s->ch_a == NULL)
		print_error("no way found.");
	ft_putstr(s->input);
	ft_putchar('\n');
	print_way(s, ch_sh_way(s));
}


/*
	int i = 0;
	int j = 0;
	i = -1;
	while (++i < s->ch_cnt)
	{
		j = -1;
		while (++j < s->ch_a[i]->length && s->ch_a[i]->chain[j] != -1)
		{
			printf("|%s|", get_name(s, s->ch_a[i]->chain[j]));
			if (s->ch_a[i]->chain[j + 1] != -1 || j + 1 > s->nr)
				printf("->");
		}
		printf("\n");
	}
*/
