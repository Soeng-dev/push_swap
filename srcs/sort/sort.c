/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:55:17 by soekim            #+#    #+#             */
/*   Updated: 2021/05/29 16:17:15 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

void		sort_ascend(t_data *data)
{
	int		i;
	t_list	*front;
	t_list	*back;

	front = data->stack;
	while (front)
	{
		back = front->next;
		while (back)
		{
			if (*(int *)back->content < *(int *)front->content)
			{
				i = *(int *)back->content;
				*(int *)back->content = *(int *)front->content;
				*(int *)front->content = i;
			}
			back = back->next;
		}
		front = front->next;
	}
	i = *(int *)data->loaf->content;
	pop(&data->loaf);
	while (--i >= 0)
		st_add(&data->loaf, 1);
	return ;
}

void		sort(t_input *input)
{
	t_sort_info		info;

	while (is_divided(input->a.loaf) == FALSE)
	{
		divide_loaf(&info, input, A_TO_B);
		if (is_divided(input->b.loaf))
			move_loaf(input, B_TO_A);
		while (is_divided(input->b.loaf) == FALSE)
		{
			divide_loaf(&info, input, B_TO_A);
		}
	}
	return ;
}
