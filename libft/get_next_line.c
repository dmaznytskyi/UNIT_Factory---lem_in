/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:40:29 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/06 13:36:34 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ns(int fd, t_gnl *head)
{
	t_gnl	*new;

	new = (t_gnl*)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->n = 0;
	new->n2 = 0;
	new->s = NULL;
	new->next = head;
	head = new;
	return (head);
}

int		reader(t_gnl *curr)
{
	int		i;
	char	*t;

	i = 0;
	i = read(curr->fd, curr->tmp, BUFF_SIZE);
	if (i == 0)
		return (0);
	curr->tmp[i] = '\0';
	curr->n += i;
	if (!curr->s)
		curr->s = ft_strdup(curr->tmp);
	else
	{
		t = curr->s;
		curr->s = ft_strjoin(curr->s, curr->tmp);
		free(t);
	}
	ft_bzero(curr->tmp, BUFF_SIZE);
	if (!ft_strchr(curr->s + curr->n2, '\n'))
		reader(curr);
	return (1);
}

int		bnl(t_gnl *curr, char **line)
{
	char	*a;
	int		i;

	i = 0;
	if (reader(curr) == 0 && curr->n <= 0)
		return (0);
	a = (char*)malloc(sizeof(char) * ft_strlen(curr->s));
	while (curr->s[curr->n2] != '\n' && curr->s[curr->n2] != '\0')
	{
		a[i] = curr->s[curr->n2];
		i++;
		curr->n2++;
		curr->n -= 1;
	}
	if (curr->s[curr->n2] != '\0')
		curr->n2++;
	a[i] = '\0';
	curr->n -= 1;
	*line = a;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*head = 0;
	t_gnl			*tmp;
	char			*t;

	t = (char*)malloc(sizeof(char) * 10);
	if (fd < 0 || (read(fd, t, 0)) < 0)
	{
		free(t);
		return (-1);
	}
	free(t);
	if (!head)
		head = ns(fd, head);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (bnl(tmp, line));
		else
			tmp = tmp->next;
	}
	head = ns(fd, head);
	return (bnl(head, line));
}
