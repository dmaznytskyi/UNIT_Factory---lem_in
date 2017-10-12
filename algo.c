/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 22:04:10 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/12 15:27:46 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	algo(t_lem *s)
{
	ft_putstr(s->input);
	int i = 0;
	int j = 0;
	while (i < s->dim)
	{
		j = 0;
		while (j < s->dim)
		{
			printf("%d ", s->c[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
