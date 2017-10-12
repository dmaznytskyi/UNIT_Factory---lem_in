/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:17:27 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/12 18:48:27 by dmaznyts         ###   ########.fr       */
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
	algo(&s);
	return (0);
}
