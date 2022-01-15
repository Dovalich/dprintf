/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:42:09 by nammari           #+#    #+#             */
/*   Updated: 2022/01/15 19:43:41 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

//      1 / 5 functions

bool	is_specifier(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 's'
		|| c == 'p' || c == 'u' || c == 'x'
		|| c == 'X')
		return (true);
	return (false);
}

bool	ft_ishex(char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (true);
	return (false);
}
