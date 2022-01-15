/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:59:11 by nammari           #+#    #+#             */
/*   Updated: 2022/01/15 19:43:03 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

//      5 / 5 functions

t_var_func	*new_struct(int format,
					int (*ptr_func)(va_list *, const char *, int))
{
	t_var_func	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->format = format;
	new->treat_function = ptr_func;
	new->next = NULL;
	return (new);
}

t_var_func	*create_list(void)
{
	t_var_func	*begin;
	int			ret;

	ret = 0;
	begin = new_struct('c', &treat_char);
	if (!begin)
		return (NULL);
	ret += list_add_front(&begin, new_struct('s', &treat_string));
	ret += list_add_front(&begin, new_struct('%', &treat_percent));
	ret += list_add_front(&begin, new_struct('d', &treat_digit));
	ret += list_add_front(&begin, new_struct('e', &treat_digit));
	ret += list_add_front(&begin, new_struct('f', &treat_digit));
	ret += list_add_front(&begin, new_struct('g', &treat_digit));
	ret += list_add_front(&begin, new_struct('i', &treat_digit));
	ret += list_add_front(&begin, new_struct('n', &treat_digit));
	ret += list_add_front(&begin, new_struct('p', &treat_digit));
	ret += list_add_front(&begin, new_struct('x', &treat_digit));
	ret += list_add_front(&begin, new_struct('X', &treat_digit));
	ret += list_add_front(&begin, new_struct('u', &treat_digit));
	if (ret > 0)
		return (NULL);
	return (begin);
}

int	list_add_front(t_var_func **list, t_var_func *ls_new)
{
	int	ret;

	ret = 0;
	if (!ls_new)
	{
		ft_putstr_fd("Chain creation failed.\n", 2);
		++ret;
	}
	if (!*list)
	{
		*list = ls_new;
		++ret;
		return (ret);
	}
	if (ls_new)
	{
		ls_new->next = *list;
		*list = ls_new;
	}
	return (ret);
}

t_var_func	*get_element(t_var_func *ptr, char c)
{
	t_var_func	*current;

	current = ptr;
	if (!current)
		return (NULL);
	while (current)
	{
		if (current->format == c)
			return (current);
		current = current->next;
	}
	return (ptr);
}

void	free_list(t_var_func *ptr)
{
	t_var_func	*tmp;

	tmp = ptr;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}
