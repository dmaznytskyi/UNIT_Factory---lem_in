/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:17:27 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/17 20:29:58 by dmaznyts         ###   ########.fr       */
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
	destroy(&s);
	while (1)
		;
	return (0);
}
