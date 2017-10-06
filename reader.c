/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:56:56 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/06 20:20:27 by dmaznyts         ###   ########.fr       */
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
	t_r		*r;

	r = (t_r*)malloc(sizeof(t_r));
	if (line[1] == '#')
	{
		if (ft_strequ(line, "##start\0") == 1)
		{
			tm = ft_strsplit(lgnl(&tmp, 1), ' ');
			if (split_cnt(tm) == 3)
				check_room(tm);
			else
				print_error("invalid room expression");i
			//свої лісти для структури кімнат (скопіювать дизайн з т_ліст)
			r->name = ft_strdup(tm[0]);
			r->x = ft_atoi(tm[1]);
			r->y = ft_atoi(tm[2]);
		}
		else if ()
		{
			//те саме що в умові вище. Винести умову вище в окрему функцію
		}
	//зpaзу записати кімнату старт-енд
}

void	lorr(char *line, t_lem *s)
{
	
}

void	reader(t_lem *s)
{
	char	*line;
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
		
	}
}
