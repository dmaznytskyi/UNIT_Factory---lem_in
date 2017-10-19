/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:17:27 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/19 13:21:28 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int	main(void)
{
	t_lem	s;

	init(&s);
	reader_l(&s);
	if (!ch_l_avail(&s))
		print_error("no links entered.");
	if (!se_link(&s, 's') || !se_link(&s, 'e'))
		print_error("no link to start or end room.");
	ft_putstr(s.input);
	algo(&s);
	LEAK;
	return (0);
}
