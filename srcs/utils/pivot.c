/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:59:03 by soekim            #+#    #+#             */
/*   Updated: 2021/06/21 20:30:14 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

t_int_arr	lst_to_int_arr(t_list *src)
{
	t_int_arr	int_arr;
	int			*curr;

	int_arr.size = ft_lstsize(src);
	int_arr.data = (int *)malloc(int_arr.size * sizeof(int));
	curr = int_arr.data;
	while (src)
	{
		*curr = *(int *)src->content;
		src = src->next;
		++curr;
	}
	return (int_arr);
}

void		sort_asc(t_int_arr *int_arr)
{
	int		*front;
	int		*back;
	int		smaller;

	front = int_arr->data;
	while (front < int_arr->data + int_arr->size - 1)
	{
		back = front + 1;
		while (back < int_arr->data + int_arr->size)
		{
			if (*back < *front)
			{
				smaller = *back;
				*back = *front;
				*front = smaller;
			}
			++back;
		}
		++front;
	}
	return ;
}

int			get_pivot(t_data *data)
{
	t_int_arr	int_arr;
	int			pivot;

	if (*(int *)data->loaf->content == 1)
		return (*(int *)data->stack->content);
	int_arr = lst_to_int_arr(data->stack);
	int_arr.size = *(int *)data->loaf->content;
	sort_asc(&int_arr);
	pivot = int_arr.data[int_arr.size / 2];
	pivot = (pivot + int_arr.data[int_arr.size / 2 - 1]) / 2;
	free(int_arr.data);
	int_arr.data = NULL;
	return (pivot);
}
