/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:56:46 by soekim            #+#    #+#             */
/*   Updated: 2021/06/03 15:17:10 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

static void	count_rotate(t_sort_info *info, int *count_r)
{
	int		i;
	int		count;
	t_list	*target;

	i = *(int *)info->orig.data->loaf->content;
	target = info->orig.data->stack;
	count = 0;
	while (--i >= 0)
	{
		++count;
		if (info->move.rule									\
			(*(int *)target->content, info->pivot) == TRUE)
			*count_r = count;
		target = target->next;
	}
	return ;
}

static void	count_revrot(t_sort_info *info, int *count_rr)
{
	t_list	*target;
	int		i;

	target = info->orig.data->stack;
	*count_rr = ft_lstsize(target);
	i = *(int*)info->orig.data->loaf->content;
	while (--i >= 0)
	{
		if (info->move.rule									\
			(*(int *)target->content, info->pivot) == TRUE)
			break;
		--(*count_rr);
		target = target->next;
	}
	i = *(int*)info->orig.data->loaf->content;
	target = info->orig.data->stack;
	while (--i >= 0)
	{
		if (info->move.rule									\
			(*(int *)target->content, info->pivot) == TRUE)
			++(*count_rr);
		target = target->next;
	}
	return ;
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
	int		count_r;
	int		count_rr;

	count_r = 0;
	count_rr = 0;
	ft_memset(info, 0, sizeof(t_sort_info));
	set_target(info, input, from_to);
	info->pivot = get_mid(info->orig.data) + 1;
	info->move.rule = is_smaller;
	count_rotate(info, &count_r);
	count_revrot(info, &count_rr);
	if (count_r <= count_rr)
	{
		info->move.count = count_r;
		info->move.func = move_by_r;
	}
	else
	{
		info->move.count = count_rr;
		info->move.func = move_by_rr;
	}
	return ;
}
