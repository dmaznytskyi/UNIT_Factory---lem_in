/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:41:16 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/15 21:56:15 by dmaznyts         ###   ########.fr       */
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

int		on_ch(t_lem *s, int what, int ch_loc)
{
	int	i;

	i = -1;
	while (++i < s->ch_a[ch_loc]->length)
		if (s->ch_a[ch_loc]->chain[i] == what)
			return (1);
	return (0);
}

void	add_room(t_lem *s, int nr, int ch_loc)
{
	int	*upd;
	int	i;

	i = -1;
	s->ch_a[ch_loc]->length++;
	upd = (int*)malloc(sizeof(int) * s->ch_a[ch_loc]->length);
	while (++i < s->ch_a[ch_loc]->length - 1)
		upd[i] = s->ch_a[ch_loc]->chain[i];
	upd[i] = nr;
//	free(s->ch_a[ch_loc]->chain);
	s->ch_a[ch_loc]->chain = upd;
	if (nr == get_e(s))
		s->ch_a[ch_loc]->end = 1;
}

void	fork_chain(t_lem *s)
{
	//realloc memory for chain array
	//rewrite last chain to free space
	//допихать чейн_локейшн во все функции с чейном
	t_ch	**new_ch;
	int		i;
	int		j;

	i = -1;
	s->ch_cnt++;
	new_ch = (t_ch**)malloc(sizeof(t_ch*) * s->ch_cnt);
	while (++i < s->ch_cnt - 1)
		new_ch[i] = s->ch_a[i];
	new_ch[i] = (t_ch*)malloc(sizeof(t_ch) * s->ch_a[i - 1]->length);
	new_ch[i]->chain = (int*)malloc(sizeof(int) * s->ch_a[i - 1]->length + 1);
	j = -1;
	while (++j < s->ch_a[i - 1]->length)
		new_ch[i]->chain[j] = s->ch_a[i - 1]->chain[j];
//	free(s->ch_a);
	s->ch_a = new_ch;
	find_ways(s, get_s(s), get_e(s), i - 1);
}
/*
void	find_ways(t_lem *s, int to, int ch_loc)
{
	//скипать если номер комнаты в цикле содержится в чейне
	//если номер комнаты == енду, останавливать поиск пути, вычислять его длину
	//если енд не достижим - кидать эрор (хоть это и не правильно)
	int		i;

	i = -1;
	while (++i < s->dim)
	{
		if (s->c[to][i] == 1 && !on_ch(s, i, ch_loc))
		{
			add_room(s, i, ch_loc);
			find_ways(s, i, ch_loc);
			if (smth_left(s, to, i))
			{
				fork_chain(s);
				ch_loc++;
			}
		}
	}
}*/

void	find_ways(t_lem *s, int start, int end, int ch)
{
	int	r1;
	int	r2;

	r1 = start;
	r2 = -1;
	while (++r2 < s->dim)
	{
		if (s->c[r1][r2] == 1 && !on_ch(s, r1, ch))
		{
			add_room(s, r1, ch);
			if (r1 == end)
				break ;
			r1 = r2;
			r2 = -1;
		}
	}
	if (ch < 10)
		fork_chain(s);
	if (r2 == s->dim && r1 == end)
		print_error("no error (just kidding)");
}
