/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:56:56 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/06 17:58:15 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	nli(char *line, t_lem *s)
{
	
}

void	ant_num(char *line, t_lem *s)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(line))
		if (!ft_isdigit(line[i]))
			print_error("invalid ant expression");
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
		{
			tm = ft_strsplit(lgnl(&tmp, 1));
			if (split_cnt(tm) == 3)
				check_room(tm);
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
