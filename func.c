/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:41:16 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/11 22:28:47 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

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
//	printf("new room |%s|%d|%d|\n", r->name, r->x, r->y);
	if (!s->r)
		s->r = rlstnew(r);
	else
		rlstadd(&s->r, rlstnew(r));
}

void	add_input(t_lem *s, char *line)
{
	char	*tmp;

	tmp = s->input;
	s->input = ft_strjoin(s->input, "\n");
	ft_strdel(&tmp);
	tmp = s->input;
	s->input = ft_strjoin(s->input, line);
	ft_strdel(&tmp);
	ft_strdel(&line);
}

void	enumerate(t_lem *s)
{
	int	i;
	int	j;
	t_l	*tmp;

	i = -1;
	tmp = s->r;
	while (tmp)
	{
		tmp->room->nr = ++i;
		tmp = tmp->next;
	}
	s->c = (char**)malloc(sizeof(char*) * ++i);
	s->c[i] = NULL;
	j = -1;
	while (++j < i)
		s->c[j] = ft_strnew(i);
	free(tmp);
}

int		ch_r_name(t_lem *s, char *n)
{
	t_l	*tmp;

	tmp = s->r;
	while (tmp)
	{
//		printf("on check room name |%s|%s|\n", tmp->room->name, n);
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
