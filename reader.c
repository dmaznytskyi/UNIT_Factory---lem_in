/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:56:56 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/10 13:45:27 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	check_room(char **s)
{
	num_check(s[1], "invalid room expression");
	num_check(s[2], "invalid room expression");
}

void	nli(char *line, t_lem *s)
{
	
}

void	parse_se(t_lem *s, int se, char **tm, t_r *r)
{
	char	*tmp;

	tm = ft_strsplit(lgnl(&tmp, 1), ' ');
	if (split_cnt(tm) == 3)
		check_room(tm);
	else
		print_error("invalid room expression");
	new_room(s, tm[0], ft_atoi(tm[1]), ft_atoi(tm[2]));
	se == 1 ? (s->r->s = 1) :
		(s->r->e = 1);
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
		print_error("invalid room expression");
	ft_strdel(&line);
	new_room(s, tm[0], ft_atoi(tm[1]), ft_atoi(tm[2]));
	se == 1 ? (s->r->s = 1) :
		(s->r->e = 1);
	ft_strdel(&tm[1]);
	ft_strdel(&tm[2]);
	free(tm);
}

void	ant_num(char *line, t_lem *s)
{
	num_check(line, "invalid ant expression");
	s->an = ft_atoi(line);
	if (s->an <= 0)
		print_error("amount of ants overflowed or less/equal than zero.");
	ft_strdel(&line);
}

void	comm(char *line, t_lem *s)
{
	char	*tmp;
	char	**tm;

	if (line[1] == '#')
	{
		if (ft_strequ(line, "##start\0") == 1)
			parse_se(s, 1, tm);
		else if (ft_strequ(line, "##end\0") == 1)
			parse_se(s, 0, tm);
	}
}

void	lorr(char *line, t_lem *s)
{
	char	**tm;
	t_r		*r;

	//if detected link(strchr(-)) - check start/end room existence
	if (ft_strchr(line, ' '))
		parse_room(s, line, tm, r);
	else if (ft_strchr(line, '-'))
		if (check_se(s))
			parce_link(s, line);
}

void	reader(t_lem *s)
{
	char	*line;
	char	*tmp;
	int		i;

	i = -1;
	while (lgnl(&line, 1) > 0)
	{
		++i;
		if (ft_isdigit(line[0]) && s->an == -1)
			ant_num(line, s);
		else if (line[0] == '#')
			comm(line, s);
		else
			lorr(line, s);
		add_input(s, line);
	}
}
