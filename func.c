/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:41:16 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/16 21:26:26 by dmaznyts         ###   ########.fr       */
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
	s->nr = i;
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

void	write_to_way_arr(t_lem *s)
{
	t_ch	**new_ch;
	int		i;
	int		j;

	j = -1;
	i = -1;
	s->ch_cnt++;
	new_ch = (t_ch**)malloc(sizeof(t_ch*) * s->ch_cnt);
	if (s->ch_a)
	{
		while (++i < s->ch_cnt - 1)
			new_ch[i] = s->ch_a[i];
//		free(s->ch_a);
		s->ch_a = new_ch;
	}
	else
		s->ch_a = (t_ch**)malloc(sizeof(t_ch*) * s->ch_cnt);
	s->ch_a[i] = (t_ch*)malloc(sizeof(t_ch));
	s->ch_a[i]->chain = (int*)malloc(sizeof(int) * s->nr);
	j = -1;
	while (++j < s->nr)
		s->ch_a[i]->chain[j] = s->vis[j];
	free(s->vis);
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
		if (s->c[st][i] == 1 && !on_ar(s, i))
		{
			add_to_ar(s, i);
			int abc = -1;
			while (++abc < s->nr)
				printf("%d ", s->vis[abc]);
			printf("\n");
			find_ways(s, i);
			if (i == get_e(s))
			{
				printf("final way to write\n");
				int abc = -1;
				while (++abc < s->nr)
					printf("|%d %s|", s->vis[abc], get_name(s, s->vis[abc]));
				printf("\n");
				write_to_way_arr(s);
				del_fr_ar(s);
				return ;
			}
		}
	}
	del_fr_ar(s);
	return ;
}
