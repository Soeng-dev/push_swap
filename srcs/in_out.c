/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:53:16 by soekim            #+#    #+#             */
/*   Updated: 2021/05/13 18:42:40 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/in_out.h"

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
	if (
	return (n);
}

void		read_input(char 


