/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:58:36 by soekim            #+#    #+#             */
/*   Updated: 2021/06/16 12:58:40 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int		min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

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

int		is_bigger(int target, int pivot)
{
	return (target > pivot);
}

int		is_smaller(int target, int pivot)
{
	return (target < pivot);
}
