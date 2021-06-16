/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:22:50 by soekim            #+#    #+#             */
/*   Updated: 2021/06/16 12:43:41 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

static void	sort3_a_2(int first, int second, int third, t_input *input)
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
	return ;
}

static void	sort3_a(int first, int second, int third, t_input *input)
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
		sort3_a_2(first, second, third, input);
	return ;
}

static void	sort3_btoa_2(int first, int second, int third, t_input *input)
{
	if (second < first && first < third)
	{
		cmd_repeat(cmd_p, input, 'a', 2);
		cmd_repeat(cmd_r, input, 'a', 2);
		cmd_p('a', &input->a.stack, &input->b.stack);
		cmd_r('a', &input->a.stack, &input->b.stack);
	}
	else if (third < first && first < second)
	{
		cmd_s('b', &input->a.stack, &input->b.stack);
		cmd_repeat(cmd_p, input, 'a', 3);
		cmd_repeat(cmd_r, input, 'a', 3);
	}
	else if (second < third && third < first)
	{
		cmd_p('a', &input->a.stack, &input->b.stack);
		cmd_s('b', &input->a.stack, &input->b.stack);
		cmd_repeat(cmd_p, input, 'a', 2);
		cmd_repeat(cmd_r, input, 'a', 3);
	}
	else if (third < second && second < first)
	{
		cmd_repeat(cmd_p, input, 'a', 3);
		cmd_repeat(cmd_r, input, 'a', 3);
	}
}

static void	sort3_btoa(int first, int second, int third, t_input *input)
{
	int		i;

	if (first < second && second < third)
	{
		i = 3;
		while (--i >= 0)
		{
			cmd_p('a', &input->a.stack, &input->b.stack);
			cmd_r('a', &input->a.stack, &input->b.stack);
		}
	}
	else if (first < third && third < second)
	{
		cmd_p('a', &input->a.stack, &input->b.stack);
		cmd_r('a', &input->a.stack, &input->b.stack);
		cmd_repeat(cmd_p, input, 'a', 2);
		cmd_repeat(cmd_r, input, 'a', 2);
	}
	else
		sort3_btoa_2(first, second, third, input);
	return ;
}

void		sort3_to_a(t_input *input, int from_to)
{
	int				i;
	int				first;
	int				second;
	int				third;
	t_sort_info		sort;

	set_target(&sort, input, from_to);
	first = *(int *)sort.orig.data->stack->content;
	second = *(int *)sort.orig.data->stack->next->content;
	third = *(int *)sort.orig.data->stack->next->next->content;
	if (from_to == A_TO_B)
		sort3_a(first, second, third, input);
	else if (from_to == B_TO_A)
		sort3_btoa(first, second, third, input);
	i = *(int *)sort.orig.data->loaf->content;
	pop(&sort.orig.data->loaf);
	while (--i >= 0)
	{
		st_add(&input->a.loaf, 1);
		rotate(&input->a.loaf, ROT_FORWARD);
	}
	return ;
}
