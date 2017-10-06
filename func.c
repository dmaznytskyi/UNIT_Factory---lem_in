/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:41:16 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/06 17:58:17 by dmaznyts         ###   ########.fr       */
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

	i = -1;
	while (s[++i] != NULL)
		;
	return (i);
}
