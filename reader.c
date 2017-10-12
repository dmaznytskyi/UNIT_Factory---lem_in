/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:56:56 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/12 15:34:26 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	check_room(char **s)
{
	num_check(s[1], "invalid room expression.");
	num_check(s[2], "invalid room expression.");
}

void	parse_se(t_lem *s, int se, char **tm)
{
	char	*tmp;

	get_next_line(0, &tmp);
	tm = ft_strsplit(tmp, ' ');
	if (split_cnt(tm) == 3)
		check_room(tm);
	else
		print_error("invalid room expression.");
	new_room(s, tm[0], ft_atoi(tm[1]), ft_atoi(tm[2]));
	if (se == 1)
	{
		s->r->room->s = 1;
		s->r->room->e = 0;
		s->hs = 1;
	}
	else
	{
		s->r->room->e = 1;
		s->r->room->s = 0;
		s->he = 1;
	}
	ft_strdel(&tm[1]);
	ft_strdel(&tm[2]);
	free(tm);
	s->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	parse_room(t_lem *s, char *line, char **tm)
{
	tm = ft_strsplit(line, ' ');
	if (split_cnt(tm) == 3)
		check_room(tm);
	else
		print_error("invalid room expression.");
//	printf("on parsing |%s|%d|%d|\n", tm[0], ft_atoi(tm[1]), ft_atoi(tm[2]));
	new_room(s, tm[0], ft_atoi(tm[1]), ft_atoi(tm[2]));
	ft_strdel(&tm[1]);
	ft_strdel(&tm[2]);
	free(tm);
}

void	ant_num(char *line, t_lem *s)
{
	num_check(line, "invalid ant expression.");
	s->an = ft_atoi(line);
	if (s->an <= 0)
		print_error("amount of ants overflowed or less/equal than zero.");
}

void	comm(char *line, t_lem *s)
{
	char	**tm;

	tm = NULL;
	if (line[1] == '#')
	{
		if (ft_strequ(line, "##start\0") == 1)
		{
			if (!s->hs)
				parse_se(s, 1, tm);
			else
				print_error("map can contain only one start");
		}
		else if (ft_strequ(line, "##end\0") == 1)
		{
			if (!s->he)
				parse_se(s, 0, tm);
			else
				print_error("map can contain only one end");
		}
	}
}

int		get_nr(t_lem *s, char *n)
{
	t_l	*tmp;

	tmp = s->r;
	while (tmp)
	{
		if (ft_strequ(tmp->room->name, n))
			return (tmp->room->nr);
		tmp = tmp->next;
	}
	return (-1);
}

void	new_link(t_lem *s, char *l1, char *l2)
{
	int	nr1;
	int	nr2;

	nr1 = get_nr(s, l1);
	nr2 = get_nr(s, l2);
	if (!s->c[nr1][nr2])
	{
		s->c[nr1][nr2] = 1;
		s->c[nr2][nr1] = 1;
	}
	else
		ft_putstr("Warning! Link already exists!\n");
}

void	parce_link(t_lem *s, char *line)
{
	char	**tm;

	tm = ft_strsplit(line, '-');
	if (split_cnt(tm) != 2)
		print_error("invalid link expression.");
	else
	{
		if (!ch_r_name(s, tm[0]) || !ch_r_name(s, tm[1]))
			print_error("link to non existing room.");
		else
			new_link(s, tm[0], tm[1]);
	}
}

void	lorr(char *line, t_lem *s, char *n)
{
	char	**tm;

	tm = NULL;
	if (ft_strchr(line, ' '))
		parse_room(s, line, tm);
	else if (ft_strchr(line, '-'))
	{
		if (s->hs && s->he)
		{
			!(*n) ? enumerate(s) : 0;
			*n = 1;
			parce_link(s, line);
		}
		else
			print_error("no start/end room.");
	}
}

void	reader_l(t_lem *s)
{
	char	*line;
	char	n;

	n = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]) && s->an == -1)
			ant_num(line, s);
		else if (line[0] == '#')
			comm(line, s);
		else
			lorr(line, s, &n);
		add_input(s, line);
	}
}
