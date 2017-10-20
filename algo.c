/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 22:04:10 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/20 10:38:29 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_ways(t_lem *s)
{
	int i;
	int j;

	i = 0;
	while (i < s->ch_cnt)
	{
		j = 0;
		while (j < s->ch_a[i]->length && s->ch_a[i]->chain[j] != -1)
		{
			printf("|%s|", get_name(s, s->ch_a[i]->chain[j]));
			if (s->ch_a[i]->chain[j + 1] != -1 || j + 1 > s->nr)
				printf("->");
			j++;
		}
		i++;
		printf("\n");
	}
}

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
	return (NULL);
}

void	print_ant(int nr, char *name)
{
	ft_putchar('L');
	ft_putnbr(nr);
	ft_putchar('-');
	ft_putstr(name);
}

void	print_way(t_lem *s, int way)
{
	t_ch	*ch;

	ch = s->ch_a[way];
		print_ant(1, get_name(s, s->ch_a[way]->chain[0]));
	ft_putchar('\n');
		print_ant(1, get_name(s, s->ch_a[way]->chain[1]));
			ft_putchar(' ');
		print_ant(2, get_name(s, s->ch_a[way]->chain[0]));
	ft_putchar('\n');
		print_ant(1, get_name(s, s->ch_a[way]->chain[2]));
			ft_putchar(' ');
		print_ant(2, get_name(s, s->ch_a[way]->chain[1]));
			ft_putchar(' ');
		print_ant(3, get_name(s, s->ch_a[way]->chain[0]));
	ft_putchar('\n');
		print_ant(2, get_name(s, s->ch_a[way]->chain[2]));
			ft_putchar(' ');
		print_ant(3, get_name(s, s->ch_a[way]->chain[1]));
			ft_putchar(' ');
		print_ant(4, get_name(s, s->ch_a[way]->chain[0]));
	ft_putchar('\n');
		print_ant(3, get_name(s, s->ch_a[way]->chain[2]));
			ft_putchar(' ');
		print_ant(4, get_name(s, s->ch_a[way]->chain[1]));
			ft_putchar(' ');
		print_ant(5, get_name(s, s->ch_a[way]->chain[0]));
	ft_putchar('\n');
		print_ant(4, get_name(s, s->ch_a[way]->chain[2]));
			ft_putchar(' ');
		print_ant(5, get_name(s, s->ch_a[way]->chain[1]));
			ft_putchar(' ');
		print_ant(6, get_name(s, s->ch_a[way]->chain[0]));
	ft_putchar('\n');
		print_ant(5, get_name(s, s->ch_a[way]->chain[2]));
			ft_putchar(' ');
		print_ant(6, get_name(s, s->ch_a[way]->chain[1]));
	ft_putchar('\n');
		print_ant(6, get_name(s, s->ch_a[way]->chain[2]));
	ft_putchar('\n');
}

int		ch_sh_way(t_lem *s)
{
	int i;
	int	tl;
	int	tch;

	i = -1;
	tl = s->dim;
	tch = -1;
	while (++i < s->ch_cnt)
	{
		if (s->ch_a[i]->length < tl)
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
	//print_ways(s);
}
