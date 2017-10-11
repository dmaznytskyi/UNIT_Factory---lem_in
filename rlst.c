/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:58:13 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/11 17:26:58 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	rlstadd(t_l **head, t_l *new)
{
	if (!head)
		return ;
	new->next = *head;
	*head = new;
}

t_l		*rlstnew(t_r *room)
{
	t_l	*new;

	if ((new = (t_l*)malloc(sizeof(t_l))) == NULL)
		return (NULL);
	if (!room)
		new->room = NULL;
	else
	{
		new->room = (t_r*)malloc(sizeof(t_r));
		new->room->name = ft_strdup(room->name);
		new->room->x = room->x;
		new->room->y = room->y;
	}
	new->next = NULL;
	return (new);
}
