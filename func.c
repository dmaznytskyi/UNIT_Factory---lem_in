/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:41:16 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/20 09:55:18 by dmaznyts         ###   ########.fr       */
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
	while (s[i] != NULL)
		i++;
	return (i);
}

void	num_check(char *s, char *error)
{
	int	i;
	int	tmp;

	tmp = ft_strlen(s);
	i = 0;
	if (ft_isalpha(s[i]) || (s[i] == '-' && s[i + 1] == '\0'))
		print_error(error);
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
	s->nr = i;
	init_links(s);
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
	return (0);
}

int		on_ar(t_lem *s, int i)
{
	int	tmp;

	tmp = -1;
	if (!s->vis)
		return (0);
	while (++tmp < s->nr)
		if (s->vis[tmp] == i)
			return (1);
	return (0);
}

void	add_to_ar(t_lem *s, int nr)
{
	int	i;

	i = -1;
	if (!s->vis)
	{
		s->vis = (int*)malloc(sizeof(int) * s->nr);
		while (++i < s->nr)
			s->vis[i] = -1;
		s->vis[0] = nr;
	}
	else
	{
		while (s->vis[++i] != -1)
			;
		s->vis[i] = nr;
	}
}

void write_to_way_arr(t_lem *s)
{
	t_ch **new_ch = NULL;
	t_ch **tmp = NULL;
	int  i;
	int  j;

	j = 0;
	i = 0;
	s->ch_cnt++;
	if (s->ch_a)
	{
		new_ch = (t_ch**)malloc(sizeof(t_ch*) * s->ch_cnt);
		while (i < s->ch_cnt - 1)
		{
			new_ch[i] = s->ch_a[i];
			i++;
		}
		tmp = s->ch_a;
		s->ch_a = new_ch;
		free(tmp);
	}
	else
		s->ch_a = (t_ch**)malloc(sizeof(t_ch*) * s->ch_cnt);
	s->ch_a[i] = (t_ch*)malloc(sizeof(t_ch));
	s->ch_a[i]->chain = (int*)malloc(sizeof(int) * s->nr);
	s->ch_a[i]->length = 0;
//	while (s->ch_a[i]->length - 1 < s->nr)
//	{
//		s->ch_a[i]->chain[s->ch_a[i]->length] = s->vis[s->ch_a[i]->length];
//		s->ch_a[i]->length += 1;
//	}
	while (s->ch_a[i]->length - 1 < s->nr)
		if (s->vis[s->ch_a[i]->length] != -1)
		{
			s->ch_a[i]->chain[s->ch_a[i]->length] = s->vis[s->ch_a[i]->length];
			s->ch_a[i]->length += 1;
		}
		else
			break ;
	s->ch_a[i]->chain[s->ch_a[i]->length - 1] = get_e(s);
}

void	del_fr_ar(t_lem *s)
{
	int	i;

	i = -1;
	while (s->vis[++i] >= 0 && i < s->nr)
		;
	s->vis[i - 1] = -1;
}

void	find_ways(t_lem *s, int st)
{
	int	i;

	i = -1;
	while (++i < s->dim)
	{
		if (s->c[st][i] == 1 && !on_ar(s, i) && i != get_s(s))
		{
			add_to_ar(s, i);
			if (i == get_e(s))
			{
				write_to_way_arr(s);
				del_fr_ar(s);
			}
			else
				find_ways(s, i);
		}
	}
	del_fr_ar(s);
	return ;
}
