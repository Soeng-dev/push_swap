/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:56:46 by soekim            #+#    #+#             */
/*   Updated: 2021/05/28 19:48:06 by soekim           ###   ########.fr       */
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
	*count_r = 0;
	while (--i >= 0)
	{
		if (*(int *)target->content > info->pivot)
			*count_r = count;
		++count;
		target = target->next;
	}
	return ;
}

static void	count_revrot(t_sort_info *info, int *count_rr)
{
	t_list	*target;
	int		i;

	target = info->orig.data->stack;
	i = *(int*)info->orig.data->loaf->content;
	*count_rr = ft_lstsize(target);
	while (--i >= 0)
	{
		if (*(int *)target->content > info->pivot)
			break;
		--count_rr;
		target = target->next;
	}
	i = *(int*)info->orig.data->loaf->content;
	target = info->orig.data->stack;
	while (--i >= 0)
	{
		if (*(int *)target->content > info->pivot)
			++count_rr;
		target = target->next;
	}
	return ;
}

static void	set_target(t_sort_info *info, t_input *input, int from_to)
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
		info->orig.name = 'a';
		info->dest.data = &input->a;
	}
	return ;
}

void		set_sort_info(t_sort_info *info, t_input *input, int from_to)
{
	int		count_r;
	int		count_rr;

	ft_memset(info, 0, sizeof(t_sort_info));
	set_target(info, input, from_to);
	info->pivot = get_mid(info->orig.data);
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
	if (from_to == A_TO_B)
		info->move.rule = is_bigger;
	else if (from_to == B_TO_A)
		info->move.rule = is_smaller;
	return ;
}
