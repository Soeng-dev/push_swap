/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:22:50 by soekim            #+#    #+#             */
/*   Updated: 2021/05/31 17:01:12 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

# include <stdio.h>

static int	sort3_a_1(int first, int second, int third, t_input *input)
{
	if (first < second && second < third)
		cmd_repeat(cmd_r, input, 'a', 3);
	else if (first < third && third < second)
	{
		cmd_r('a', &input->a.stack, &input->b.stack);
		cmd_s('a', &input->a.stack, &input->b.stack);
		cmd_repeat(cmd_r, input, 'a', 2);
	}
	else if (second < first && first < third)
	{
		cmd_s('a', &input->a.stack, &input->b.stack);
		cmd_repeat(cmd_r, input, 'a', 3);
	}
	else if (third < first && first < second)
	{
		cmd_p('b', &input->a.stack, &input->b.stack);
		cmd_s('a', &input->a.stack, &input->b.stack);
		cmd_r('a', &input->a.stack, &input->b.stack);
		cmd_p('a', &input->a.stack, &input->b.stack);
		cmd_repeat(cmd_r, input, 'a', 2);
	}
	else
		return (0);
	return (1);
}

static int	sort3_a_2(int first, int second, int third, t_input *input)
{
	if (second < third && third < first)
	{
		cmd_p('b', &input->a.stack, &input->b.stack);
		cmd_repeat(cmd_r, input, 'a', 2);
		cmd_p('a', &input->a.stack, &input->b.stack);
		cmd_r('a', &input->a.stack, &input->b.stack);
	}
	else if (third < second && second < first)
	{
		cmd_p('b', &input->a.stack, &input->b.stack);
		cmd_s('a', &input->a.stack, &input->b.stack);
		cmd_repeat(cmd_r, input, 'a', 2);
		cmd_p('a', &input->a.stack, &input->b.stack);
		cmd_r('a', &input->a.stack, &input->b.stack);
	}
	else
		return (0);
	return (1);
}
//
//static void	sort3_btoa(int first, int second, int third, t_input *input)
//{
//	
//	push(&input->a.loaf, &input->b.loaf);
//}


//if too many commands change to use sort3_btoa
void		sort3_to_a(t_input *input, int from_to)
{
	int				first;
	int				second;
	int				third;
	t_sort_info		sort;

	if (from_to == B_TO_A)
		move_loaf(input, B_TO_A);
	set_target(&sort, input, from_to);
	first = *(int *)input->a.stack->content;
	second = *(int *)input->a.stack->next->content;
	third = *(int *)input->a.stack->next->next->content;
//	first = *(int *)sort.orig.data->stack->content;
//	second = *(int *)sort.orig.data->stack->next->content;
//	third = *(int *)sort.orig.data->stack->next->next->content;
	if (sort3_a_1(first, second, third, input))
	{}
	else
		sort3_a_2(first, second, third, input);

//	if (from_to == A_TO_B)
//	{
//		sort3_a_1(first, second, third, input);
//		sort3_a_2(first, second, third, input);
//	}
//	else if (from_to == B_TO_A)
//	{
//		
//	}
	return ;
}
