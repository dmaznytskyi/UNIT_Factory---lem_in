/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:56:56 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/10 20:57:50 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	check_room(char **s)
{
	num_check(s[1], "invalid room expression.");
	num_check(s[2], "invalid room expression.");
}

int		check_se(t_lem *s)
{
	t_l		*tmp;
	char	flag;

	tmp = s->r;
	flag = 0;
	while (tmp)
	{
		if (tmp->room->s || tmp->room->e)
			flag++;
		tmp = tmp->next;
	}
	if (flag == 2)
		return (1);
	else
		return (0);
}

void	parse_se(t_lem *s, int se, char **tm)
{
	char	*tmp;

	lgnl(&tmp, 1);
	tm = ft_strsplit(tmp, ' ');
	if (split_cnt(tm) == 3)
		check_room(tm);
	else
		print_error("invalid room expression.");
	new_room(s, tm[0], ft_atoi(tm[1]), ft_atoi(tm[2]));
	if (se == 1)
	{
		s->r->room->s = 1;
		s->hs = 1;
	}
	else
	{
		s->r->room->e = 1;
		s->he = 1;
	}
	ft_strdel(&tm[1]);
	ft_strdel(&tm[2]);
	free(tm);
}

void	parse_room(t_lem *s, char *line, char **tm)
{
	tm = ft_strsplit(line, ' ');
	if (split_cnt(tm) == 3)
		check_room(tm);
	else
		print_error("invalid room expression.");
	ft_strdel(&line);
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
	ft_strdel(&line);
}

void	comm(char *line, t_lem *s)
{
	char	**tm;

	tm = NULL;
	if (line[1] == '#')
	{
		if (ft_strequ(line, "##start\0") == 1 && !s->hs)
			parse_se(s, 1, tm);
		else if (ft_strequ(line, "##end\0") == 1 && !s->he)
			parse_se(s, 0, tm);
	}
}

void	parce_link(t_lem *s, char *line)
{
	char	**tm;

	tm = ft_strsplit(line, '-');
	if (split_cnt(tm) != 2)
		print_error("invalid link expression.");
	else
	{
		(void)s;
	}
	//make array of connections of rooms
}

void	lorr(char *line, t_lem *s, char *n)
{
	char	**tm;

	tm = NULL;
	if (ft_strchr(line, ' '))
		parse_room(s, line, tm);
	else if (ft_strchr(line, '-'))
	{
		if (check_se(s))
		{
			!(*n) ? enumerate(s) : 0;
			parce_link(s, line);
		}
		else
			print_error("no start/end room.");
	}
}

void	reader_l(t_lem *s)
{
	char	*line;
	int		i;
	char	n;

	i = -1;
	n = 0;
	while (lgnl(&line, 1) > 0)
	{
		++i;
		if (ft_isdigit(line[0]) && s->an == -1)
			ant_num(line, s);
		else if (line[0] == '#')
			comm(line, s);
		else
			lorr(line, s, &n);
		add_input(s, line);
	}
}
