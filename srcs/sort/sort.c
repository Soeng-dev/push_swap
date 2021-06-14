/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:55:17 by soekim            #+#    #+#             */
/*   Updated: 2021/06/14 19:48:32 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

static void	sort2_to_a(t_input *input, int from_to)
{
	int		i;

	if (from_to == A_TO_B && loaf_is_ascending(&input->a) == FALSE)
		cmd_s('a', &input->a.stack, &input->b.stack);
	else if (from_to == B_TO_A)
	{
		if (loaf_is_ascending(&input->b))
			cmd_s('b', &input->a.stack, &input->b.stack);
		move_loaf(input, B_TO_A);
	}
	cmd_repeat(cmd_r, input, 'a', 2);
	pop(&input->a.loaf);
	i = 2;
	while (--i >= 0)
		st_add_last(&input->a.loaf, 1);
	return ;
}

void		sort_directly(t_input *input, int from_to)
{
	t_data	*tar_data;

	if (from_to == A_TO_B)
		tar_data = &(input->a);
	else
		tar_data = &(input->b);
	if (!tar_data->loaf || !tar_data->stack)
		return ;
	if (*(int *)tar_data->loaf->content == 2)
		sort2_to_a(input, from_to);
	else if (*(int *)tar_data->loaf->content == 3)
		sort3_to_a(input, from_to);
	return ;
}

void		sort(t_input *input)
{
	t_sort_info		info;

	while (is_sorted(input) == FALSE)
	{
		if (*(int *)input->a.loaf->content == 2 || 
			*(int *)input->a.loaf->content == 3)
			sort_directly(input, A_TO_B);
		else
		{
			divide_move(&info, input, A_TO_B);
//			printf("\n\nafter divmove \n");
//			print_stacks(input);	print_loaf(input);
			while (input->b.loaf)
			{
				if (*(int *)input->b.loaf->content == 2 || 
					*(int *)input->b.loaf->content == 3)
				{sort_directly(input, B_TO_A);
//					printf("\n\nafter st dir btoa\n");
//					print_stacks(input);	print_loaf(input);
				}
				else
				{
					divide_move(&info, input, B_TO_A);
					rotate_loaf('a', input);
				}
			}
			if (is_divided(input->a.loaf) && !input->b.loaf)
			{
				int		i;
				int		mark;
				int		smallest;
				t_cmd	sort_cmd;
				t_list	*st;

				smallest = INT_MAX;
				i = 0;
				st = input->a.stack;
				while (st)
				{
					++i;
					if (*(int *)st->content < smallest)
					{
						mark = i;
						smallest = *(int *)st->content;
					}
					st = st->next;
				}
				if (mark < ft_lstsize(input->a.stack) / 2)
					sort_cmd = cmd_r;
				else
					sort_cmd = cmd_rr;
				while (is_sorted(input) == FALSE)
				{
					sort_cmd('a', &input->a.stack, &input->b.stack);
				//	rotate_loaf('a', input);
//					print_stacks(input);	print_loaf(input);
//					char c;
//					scanf("%c", &c);
				}
			}
		}
	}
}
