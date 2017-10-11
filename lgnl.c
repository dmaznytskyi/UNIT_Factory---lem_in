/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:43:05 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/11 17:18:40 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int	lgnl(char **line, int st)
{
	char	*b;
	char	*r;
	char	*tmp;

	r = ft_strnew(0);
	b = ft_strnew(1);
	while (!ft_strchr(r, '\n') && st != 0)
	{
		st = read(0, b, 1);
		tmp = r;
		r = ft_strjoin(r, b);
		ft_strdel(&tmp);
	}
	if (ft_strlen(r) > 0)
		st = 1;
	if (ft_strchr(r, '\n'))
		r[ft_strlen(r) - 1] = '\0';
	ft_strdel(&b);
	*line = r;
	return (st);
}
