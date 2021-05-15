/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:53:16 by soekim            #+#    #+#             */
/*   Updated: 2021/05/15 20:12:39 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/input.h"

void	pass_charset(char **str, const char *set)
{
	if (!str || !(*str))
		return ;
	while (**str)
	{
		if (is_element(set, **str))
			(*str)++;
		else
			return ;
	}
	return ;
}

int		read_int(char *s, int *is_error)
{
	long int	n;

	n = 0;
	pass_charset(&s, " \t\f");
	n = ft_atoi(s);
	if (*s == '-')
		++s;
	if (ft_isdigit(*s) == FALSE)
		*is_error = TRUE;
	pass_charset(&s, "0123456789");
	if (*s)
		*is_error = TRUE;
	return (n);
}

void	read_input(char **input, t_list **st)
{
	int		is_error;

	is_error = FALSE;
	while (*input)
	{
		st_add(st, read_int(*input, &is_error));
		input++;
	}
	if (is_error)
	{
		ft_lstclear(st, free);
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
	return ;
}
