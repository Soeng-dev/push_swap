/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:55:17 by soekim            #+#    #+#             */
/*   Updated: 2021/06/05 16:54:52 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

void		move_by_r(void *sort_info, t_input *input)
{
	int			i;
	int			moved;
	int			unmoved;
	t_sort_info	*info;

	info = (t_sort_info *)sort_info;
	i = info->move.count;
	moved = 0;
	unmoved = *(int *)info->orig.data->loaf->content;
	while (--i >= 0)
	{
		if (info->move.rule												\
			(*(int *)info->orig.data->stack->content, info->pivot)		\
			== TRUE)
		{
			cmd_p(info->dest.name, &input->a.stack, &input->b.stack);
			++moved;
			--unmoved;
		}
		else
			cmd_r(info->orig.name, &input->a.stack, &input->b.stack);
	}
	if (unmoved == 0)
		pop(&info->orig.data->loaf);
	else
		*(int *)info->orig.data->loaf->content = unmoved;
	if (moved)
		st_add(&info->dest.data->loaf, moved);
	return ;
}

void		move_by_rr(void *sort_info, t_input *input)
{
	int			i;
	int			moved;
	int			unmoved;
	t_sort_info	*info;

	info = (t_sort_info *)sort_info;
	i = info->move.count;
	moved = 0;
	unmoved = *(int *)info->orig.data->loaf->content;
	while (--i >= 0)
	{
		cmd_rr(info->orig.name, &input->a.stack, &input->b.stack);
		if (info->move.rule												\
			(*(int *)info->orig.data->stack->content, info->pivot)		\
			== TRUE)
		{
			cmd_p(info->dest.name, &input->a.stack, &input->b.stack);
			++moved;
			--unmoved;
		}
	}
	if (unmoved == 0)
		pop(&info->orig.data->loaf);
	else
		*(int *)info->orig.data->loaf->content = unmoved;
	if (moved)
		st_add(&info->dest.data->loaf, moved);
	return ;
}

void		rotate_loaf(char target, t_input *input)
{
	int		i;

	if (target == 'a')
		i = *(int *)input->a.loaf->content;
	else if (target == 'b')
		i = *(int *)input->b.loaf->content;
	else
		return ;
	cmd_repeat(cmd_r, input, target, i);
	if (target == 'a')
		rotate(&input->a.loaf, ROT_FORWARD);
	else if (target == 'b')
		rotate(&input->b.loaf, ROT_FORWARD);
//	printf("\n\nafter rf\n");
//	print_stacks(input);		print_loaf(input);
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

//divided loaf is moved to bottom of dest loaf when from A to B
void		divide_move(t_sort_info *info, t_input *input, int from_to)
{
	set_sort_info(info, input, from_to);
//	if (from_to == B_TO_A &&
//		(*(int *)input->b.loaf->content == 2 || 
//		*(int *)input->b.loaf->content == 3))
//	{
//		sort_directly(input, B_TO_A);
//	}
//	else
	info->move.func(info, input);

//	printf("\n\ndivide pivot : %d\n", info->pivot);
//	print_stacks(input);
//	print_loaf(input);

	return ;
}
