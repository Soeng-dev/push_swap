/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:55:17 by soekim            #+#    #+#             */
/*   Updated: 2021/05/28 19:59:38 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

void		move_by_r(void *sort_info, t_input *input)
{
	int			i;
	t_sort_info	*info;

	info = (t_sort_info *)sort_info;
	i = info->move.count;
	while (--i >= 0)
	{
		if (info->move.rule												\
			(*(int *)info->orig.data->stack->content, info->pivot)		\
			== TRUE)
			cmd_p(info->dest.name, &input->a.stack, &input->b.stack);
		else
			cmd_r(info->orig.name, &input->a.stack, &input->b.stack);
	}
	*(int *)info->orig.data->loaf->content								\
	= ft_lstsize(info->orig.data->stack);
	st_add(&info->dest.data->loaf, ft_lstsize(info->dest.data->stack));
	return ;
}

void		move_by_rr(void *sort_info, t_input *input)
{
	int			i;
	t_sort_info	*info;

	info = (t_sort_info *)sort_info;
	i = info->move.count;
	while (--i >= 0)
	{
		cmd_rr(info->orig.name, &input->a.stack, &input->b.stack);
		if (info->move.rule												\
			(*(int *)info->orig.data->stack->content, info->pivot)		\
			== TRUE)
			cmd_p(info->dest.name, &input->a.stack, &input->b.stack);
	}
	*(int *)info->orig.data->loaf->content								\
	= ft_lstsize(info->orig.data->stack);
	st_add(&info->dest.data->loaf, ft_lstsize(info->dest.data->stack));
}

void		divide_loaf(t_sort_info *info, t_input *input, int from_to)
{
	set_sort_info(info, input, from_to);
	if (*(int *)info->orig.data->loaf->content > 3)
		info->move.func(info, input);
	/*need to change below*/
	else if (*(int *)info->orig.data->loaf->content == 3)
		return ;
	else if (*(int *)info->orig.data->loaf->content == 2)
		return ;
	return ;
}

void		sort(t_input *input)
{
	t_sort_info		info;

	divide_loaf(&info, input, A_TO_B);
	while (is_divided(input->b.loaf) == FALSE)
	{
		divide_loaf(&info, input, B_TO_A);
	}
	return ;
}
