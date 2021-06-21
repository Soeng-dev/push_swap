/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:12:38 by soekim            #+#    #+#             */
/*   Updated: 2021/06/21 21:36:53 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

void	sort3(t_input *input)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)input->a.stack->content;
	second = *(int *)input->a.stack->next->content;
	third = *(int *)input->a.stack->next->next->content;
	if (first < third && third < second)
	{
		cmd_p('b', &input->a.stack, &input->b.stack);
		cmd_s('a', &input->a.stack, &input->b.stack);
		cmd_p('a', &input->a.stack, &input->b.stack);
	}
	else if (second < first && first < third)
		cmd_s('a', &input->a.stack, &input->b.stack);
	else if (third < first && first < second)
		cmd_rr('a', &input->a.stack, &input->b.stack);
	else if (second < third && third < first)
		cmd_r('a', &input->a.stack, &input->b.stack);
	else if (third < second && second < first)
	{
		cmd_r('a', &input->a.stack, &input->b.stack);
		cmd_s('a', &input->a.stack, &input->b.stack);
	}
	return ;
}

void	sort5(t_input *input)
{
	t_sort_info		info;

	set_sort_info(&info, input, A_TO_B);
	++info.pivot;
	info.move.rule = is_smaller;
	info.move.count = count_mincmd(&info);
	info.move.func(&info, input);
	sort3(input);
	if (loaf_is_ascending(&input->b))
		cmd_s('b', &input->a.stack, &input->b.stack);
	cmd_repeat(cmd_p, input, 'a', 2);
	return ;
}
