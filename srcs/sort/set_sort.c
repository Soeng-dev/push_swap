/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:56:46 by soekim            #+#    #+#             */
/*   Updated: 2021/06/21 21:26:26 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

int			count_mincmd(t_sort_info *info)
{
	int		i;
	int		count;
	t_list	*tar_st;

	count = 0;
	i = 0;
	tar_st = info->orig.data->stack;
	while (tar_st)
	{
		++i;
		if (info->move.rule(
			*(int *)tar_st->content, info->pivot) == TRUE)
			count = i;
		tar_st = tar_st->next;
	}
	return (count);
}

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

void		set_sort_info(t_sort_info *info, t_input *input, int from_to)
{
	ft_memset(info, 0, sizeof(t_sort_info));
	set_target(info, input, from_to);
	info->pivot = get_pivot(info->orig.data);
	if (from_to == A_TO_B)
	{
		info->move.rule = is_bigger;
		if (ft_lstsize(input->a.loaf) == 1)
			info->move.count = count_mincmd(info);
		else
			info->move.count = *(int *)info->orig.data->loaf->content;
	}
	else if (from_to == B_TO_A)
	{
		info->move.rule = is_smaller;
		info->move.count = count_mincmd(info);
	}
	info->move.func = move_by_rule;
	return ;
}
