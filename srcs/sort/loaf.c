/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:55:17 by soekim            #+#    #+#             */
/*   Updated: 2021/05/31 18:19:23 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"


# include <stdio.h>

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
	return ;
}

void		rotate_loaf(t_data *data)
{
	int		i;

	i = *(int *)data->loaf->content;
	while (--i >= 0)
		rotate(&data->stack, ROT_FORWARD);
	rotate(&data->loaf, ROT_FORWARD);
	return ;
}

void		move_loaf(t_input *input, int from_to)
{
	int			i;
	t_sort_info	move;

	ft_memset(&move, 0, sizeof(t_sort_info));
	set_target(&move, input, from_to);
	if (!move.orig.data->stack)
		return ;
	i = *(int *)move.orig.data->loaf->content;
	while (--i >= 0)
		cmd_p(move.dest.name, &input->a.stack, &input->b.stack);
	i = *(int *)move.orig.data->loaf->content;
	pop(&move.orig.data->loaf);
	st_add(&move.dest.data->loaf, i);
}

/*
** 		divide_loaf divide one loaf to two loafes if loaf bigger than 3, 
**		other wise in size-one-loafes.
*/
void		divide_loaf(t_sort_info *info, t_input *input, int from_to)
{
	set_sort_info(info, input, from_to);
	if (*(int *)info->orig.data->loaf->content > 3)
	{
		info->move.func(info, input);
		if (from_to == B_TO_A)
			rotate_loaf(&input->a);
	}
	else if (*(int *)info->orig.data->loaf->content <= 3)\
		sort_directly(input, from_to);
	return ;
}
