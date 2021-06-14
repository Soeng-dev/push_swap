
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

//	printf("pivot %d\n", pivot);
	return (pivot);
}

//int		get_mid(t_data *data)
//{
//	int		mini;
//	int		maxi;
//	int		i;
//	t_list	*list;
//
//	i = *(int *)data->loaf->content;
//	list = data->stack;
//	mini = INT_MAX;
//	maxi = INT_MIN;
//	while (--i >= 0)
//	{
//		mini = min(*(int *)list->content, mini);
//		maxi = max(*(int *)list->content, maxi);
//		list = list->next;
//	}
//	return ((mini + maxi) / 2);
//}

int			is_divided(t_list *loaf)
{
	while (loaf)
	{
		if (*(int *)loaf->content != 1)
			return (FALSE);
		loaf = loaf->next;
	}
	return (TRUE);
}

int			loaf_is_ascending(t_data *data)
{
	int		i;
	int		j;
	t_list	*front;
	t_list	*back;

	if (!data)
		return (TRUE);
	if (!data->loaf || !data->stack)
		return (TRUE);
	i = *(int *)data->loaf->content;
	front = data->stack;
	while (--i >= 1)
	{
		back = front->next;
		j = i;
		while (back && --j >= 0)
		{
			if (*(int *)front->content > *(int *)back->content)
				return (FALSE);
			back = back->next;
		}
		front = front->next;
	}
	return (TRUE);
}

int			loaf_is_descending(t_data *data)
{
	int		i;
	int		j;
	t_list	*front;
	t_list	*back;

	if (!data)
		return (TRUE);
	if (!data->loaf || !data->stack)
		return (TRUE);
	i = *(int *)data->loaf->content;
	front = data->stack;
	while (--i >= 1)
	{
		j = i;
		back = front->next;
		while (back && --j >= 0)
		{
			if (*(int *)front->content < *(int *)back->content)
				return (FALSE);
			back = back->next;
		}
		front = front->next;
	}
	return (TRUE);
}

int			is_sorted(t_input *input)
{
	t_list	*front;
	t_list	*back;

	if (input->b.stack || input->b.loaf || is_divided(input->a.loaf) == FALSE)
		return (FALSE);
	front = input->a.stack;
	while (front)
	{
		back = front->next;
		while (back)
		{
			if (*(int *)front->content > *(int *)back->content)
				return (FALSE);
			back = back->next;
		}
		front = front->next;
	}
	return (TRUE);		
}
