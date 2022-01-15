/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_sign_and_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:00:00 by nammari           #+#    #+#             */
/*   Updated: 2022/01/15 19:37:19 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

//		2 / 5

void	disp_sign(char format, t_flag_values *flag, char *string)
{
	if (format == 'd' || format == 'i' || format == 'u')
	{
		if (flag->disp_sign || *string == '-')
			ft_putchar_fd(*string, flag->fd);
		else if (flag->disp_space)
			ft_putchar_fd(' ', flag->fd);
		if ((flag->disp_sign || *string == '-')
			|| (flag->disp_space))
			flag->prefix_char_count = 1;
	}
	else if (ft_ishex(format) && (string[1] != 0 && string[1] != '0')
		&& flag->disp_hex_prefix)
	{
		if (format == 'x')
			ft_putstr_fd("0x", flag->fd);
		else if (format == 'X')
			ft_putstr_fd("0X", flag->fd);
		flag->prefix_char_count = 2;
	}
	else if (format == 'p')
	{
		ft_putstr_fd("0x", flag->fd);
		flag->prefix_char_count = 2;
	}
}

int	count_digit_prefix(t_flag_values *flag, char format, char *string)
{
	int	len;

	len = 0;
	if (ft_ishex(format) && format != 'p')
	{
		if ((flag->disp_hex_prefix) && (string[1] != 0 && string[1] != '0'))
			len = len + 2;
	}
	else if (flag->disp_space)
		++len;
	else if (flag->disp_sign)
		++len;
	else if (*string == '-')
		++len;
	else if (format == 'p')
		len = len + 2;
	return (len);
}
