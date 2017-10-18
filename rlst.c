/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:58:13 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/18 19:54:08 by dmaznyts         ###   ########.fr       */
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
		return (NULL);
	else
		new->room = room;
	new->next = NULL;
	return (new);
}
