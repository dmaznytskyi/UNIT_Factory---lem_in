/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:41:16 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/13 15:57:08 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		se_link(t_lem *s, char what)
{
	int	rn;
	int	i;

	what == 's' ? (rn = get_s(s)) : 
		(rn = get_e(s));
	i = -1;
	while (++i < s->dim)
		if (s->c[rn][i] == 1)
			return (1);
	return (0);
}

void	print_error(char *error_text)
{
	ft_putstr("\e[1;31m>>>>>>>>>> ERROR <<<<<<<<<<\e[0m ");
	ft_putstr(error_text);
	ft_putchar('\n');
	exit(0);
}

int		split_cnt(char **s)
{
	int	i;

	i = 0;
	while (s[++i] != NULL)
		;
	return (i);
}

void	num_check(char *s, char *error)
{
	int	i;
	int	tmp;

	tmp = ft_strlen(s);
	i = -1;
	while (++i < tmp)
		if (!ft_isdigit(s[i]))
			print_error(error);
}

void	new_room(t_lem *s, char *n, int x, int y)
{
	t_r	*r;

	r = (t_r*)malloc(sizeof(t_r));
	if (n[0] == 'L')
		print_error("room name cannot start with L(see pdf)");
	if (ch_r_name(s, n))
		print_error("room with this name already exists");
	if (ch_r_coord(s, x, y))
		print_error("room with this coordinates already exists");
	r->name = ft_strdup(n);
	ft_strdel(&n);
	r->x = x;
	r->y = y;
	r->s = 0;
	r->e = 0;
	if (!s->r)
		s->r = rlstnew(r);
	else
		rlstadd(&s->r, rlstnew(r));
}

void	add_input(t_lem *s, char *line)
{
	char	*tmp;

	tmp = s->input;
	if (!s->input)
		s->input = ft_strdup(line);
	else
		s->input = ft_strjoin(s->input, line);
	ft_strdel(&tmp);
	if (s->tmp)
	{
		tmp = s->input;
		s->input = ft_strjoin(s->input, "\n");
		ft_strdel(&tmp);
		tmp = s->input;
		s->input = ft_strjoin(s->input, s->tmp);
		ft_strdel(&tmp);
		ft_strdel(&s->tmp);
	}
	tmp = s->input;
	s->input = ft_strjoin(s->input, "\n");
	ft_strdel(&tmp);
	ft_strdel(&line);
}

int		ch_l_avail(t_lem *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->dim)
	{
		j = -1;
		while (++j < s->dim)
			if (s->c[i][j] == 1)
				return (1);
	}
	return (0);
}

void	enumerate(t_lem *s)
{
	int	i;
	t_l	*tmp;

	i = 0;
	tmp = s->r;
	while (tmp)
	{
		tmp->room->nr = i;
		tmp = tmp->next;
		i++;
	}
	s->dim = i;
	init_links(s);
	free(tmp);
}

int		ch_r_name(t_lem *s, char *n)
{
	t_l	*tmp;

	tmp = s->r;
	while (tmp)
	{
		if (ft_strequ(tmp->room->name, n))
			return (1);
		tmp = tmp->next;
	}
	free(tmp);
	return (0);
}

int		ch_r_coord(t_lem *s, int x, int y)
{
	t_l	*tmp;

	tmp = s->r;
	while (tmp)
	{
		if (tmp->room->x == x && tmp->room->y == y)
			return (1);
		tmp = tmp->next;
	}
	free(tmp);
	return (0);
}

int		smth_left(t_lem *s, int x, int y)
{
	while (y < s->dim)
	{
		if (s->c[x][y] == 1)
			return (1);
		y++;
	}
	return (0);
}

int		on_ch(t_lem *s, int what)
{
	int	i;

	i = -1;
	while (++i < s->ch_a->length)
		if (s->ch_a->chain[i] == what)
			return (1);
	return (0);
}

void	add_room(t_lem *s, int nr)
{
	int	*upd;
	int	i;

	i = -1;
	s->ch_a->length++;
	upd = (int*)malloc(sizeof(int) * s->ch_a->length);
	while (++i < s->ch_a->length - 1)
		upd[i] = s->ch_a->chain[i];
	upd[i] = nr;
	free(s->ch_a->chain);
	s->ch_a->chain = upd;
	if (nr == get_e(s))
		s->ch_a->end = 1;
}

void	fork(t_lem *s)
{
	//realloc memory for chain array
	//rewrite last chain to free space
	//допихать чейн_локейшн во все функции с чейном
}

void	find_ways(t_lem *s, int to)
{
	//скипать если номер комнаты в цикле содержится в чейне
	//если номер комнаты == енду, останавливать поиск пути, вычислять его длину
	//если енд не достижим - кидать эрор (хоть это и не правильно)
	t_ch	*chain;
	int		i;
	int		ch_loc;

	ch_loc = 0;
	chain = (t_ch*)malloc(sizeof(t_ch) * s->ch_cnt);
	s->ch_a[ch_loc] = chain;
	i = -1;
	while (++i < s->dim)
	{
		if (s->c[to][i] == 1 && !on_ch(s, i))
		{
			add_room(s, i);
			find_ways(s, i);
			if (smth_left(s, to, i))
			{
				s->ch_cnt++;
				fork(s);
			}
		}
	}
}
