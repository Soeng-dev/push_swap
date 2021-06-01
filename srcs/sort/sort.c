/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:55:17 by soekim            #+#    #+#             */
/*   Updated: 2021/06/01 22:39:04 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"


#include <stdio.h>

/*
**		After sort2_to_a or sort3_to_a, sorted element is rotated,
**		and input->loaf is not divided and rotated, 
**		which is dealed at sort_directly.
*/

static void	sort2_to_a(t_input *input, int from_to)
{
	if (from_to == A_TO_B && is_ascending(&input->a) == FALSE)
		cmd_s('a', &input->a.stack, &input->b.stack);
	else if (from_to == B_TO_A)
	{
		if (is_ascending(&input->b))
			cmd_s('b', &input->a.stack, &input->b.stack);
		move_loaf(input, B_TO_A);
	}
	cmd_repeat(cmd_r, input, 'a', 2);
	return ;
}

void		sort_directly(t_input *input, int from_to)
{
	int		i;
	t_data	*tar_data;

	if (from_to == A_TO_B)
		tar_data = &(input->a);
	else
		tar_data = &(input->b);
	if (*(int *)tar_data->loaf->content == 2)
		sort2_to_a(input, from_to);
	else if (*(int *)tar_data->loaf->content == 3)
		sort3_to_a(input, from_to);
	else
		return ;
	i = *(int *)input->a.loaf->content;
	pop(&input->a.loaf);
	while (--i >= 0)
	{
		st_add(&input->a.loaf, 1);
		rotate(&input->a.loaf, ROT_FORWARD);
	}
	return ;
}

void		sort(t_input *input)
{
	t_sort_info		info;

	while (is_divided(input->a.loaf) == FALSE)
	{
		while (*(int *)input->a.loaf->content == 1)
			rotate_loaf('a', input);
		divide_loaf(&info, input, A_TO_B);
		if (is_divided(input->b.loaf))
			move_loaf(input, B_TO_A);
		divide_loaf(&info, input, B_TO_A);
		while (is_divided(input->b.loaf) == FALSE)
		{
			rotate_loaf('a', input);
			divide_loaf(&info, input, B_TO_A);
		}
	}
	return ;
}
