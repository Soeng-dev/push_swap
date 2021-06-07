/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:56:46 by soekim            #+#    #+#             */
/*   Updated: 2021/06/07 20:40:43 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

void		set_target(t_sort_info *info, t_input *input, int from_to)
{
	if (from_to == A_TO_B)
	{
		info->orig.name = 'a';
		info->orig.data = &input->a;
		info->dest.name = 'b';
		info->dest.data = &input->b;
	}
	else if (from_to == B_TO_A)
	{
		info->orig.name = 'b';
		info->orig.data = &input->b;
		info->dest.name = 'a';
		info->dest.data = &input->a;
	}
	return ;
}

void		set_move(t_sort_info *info, t_input *input, int from_to)
{
	t_list	*st_b;
	int		count;

	if (from_to == A_TO_B)
	{
		info->move.rule = is_bigger;
		info->move.count = *(int *)info->orig.data->loaf->content;
	}
	else if (from_to == B_TO_A)
	{
		info->move.rule = is_smaller;
		count = 0;
		st_b = input->b.stack;
		while (st_b)
		{
			count++;
			if (info->move.rule(info->pivot, *(int*)st_b->content) == TRUE)
				info->move.count = count;
			st_b = st_b->next;
		}
	}
	info->move.func = move_by_rule;
	return ;
}

void		set_sort_info(t_sort_info *info, t_input *input, int from_to)
{
	ft_memset(info, 0, sizeof(t_sort_info));
	set_target(info, input, from_to);
	info->pivot = get_mid(info->orig.data) + 1;
	set_move(info, input, from_to);
	return ;
}
