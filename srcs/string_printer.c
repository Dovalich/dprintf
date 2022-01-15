/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:42:21 by nammari           #+#    #+#             */
/*   Updated: 2022/01/15 19:46:31 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	print_string(char	*str, t_flag_values	*flag)
{
	int				i;
	int				len;
	int				width;
	int				displayed;

	i = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_count_len(str);
	width = 0;
	displayed = 0;
	if (flag->precision_nb < len
		&& flag->precision_nb > -1 && flag->width_nb > 0)
		width = flag->width_nb - flag->precision_nb;
	else if (flag->width_nb > 0)
		width = flag->width_nb - len;
	if (flag->precision_nb > 0 && flag->precision_nb < len)
		len = flag->precision_nb;
	if (!flag->left_justify)
		displayed = print_space(&width, flag);
	if (str != NULL && str[i] && flag->precision_nb != 0)
		displayed += put_string(str, len, flag);
	displayed += print_space(&width, flag);
	return (displayed);
}

int	put_string(char	*str, int len, t_flag_values *flag)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar_fd(str[i], flag->fd);
		++i;
	}
	return (i);
}

int	print_space(int	*width, t_flag_values *flag)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = *width;
	while (tmp > 0)
	{
		ft_putchar_fd(' ', flag->fd);
		++i;
		tmp--;
	}
	*width = tmp;
	return (i);
}

int	treat_string(va_list *varlist, const char *str, int fd)
{
	char				*string;
	t_flag_values		*flag;
	char				format;
	int					display;

	format = *str;
	flag = init_to_zero(fd);
	if (wildcard_width_checker(str))
		flag->width_nb = va_arg(*varlist, int);
	if (wildcard_precision_checker(str))
		flag->precision_nb = va_arg(*varlist, int);
	string = va_arg(*varlist, char *);
	get_flag_data(str, format, flag);
	if (flag->precision_nb == -1)
		get_precision(str, format, flag);
	get_width(str, format, flag);
	if (flag->width_nb < 0)
	{
		flag->width_nb *= -1;
		flag->left_justify = true;
	}
	display = print_string(string, flag);
	free(flag);
	return (display);
}
