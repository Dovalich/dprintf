/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:43:08 by nammari           #+#    #+#             */
/*   Updated: 2022/01/15 19:44:45 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

//      4 / 5 functions

int	error_malloc(void)
{
	ft_putstr_fd("Jesus dude, your malloc failed...\n", 2);
	return (ERROR);
}

int	ft_count_len(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		++i;
	return (i);
}

int	get_biggest(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
