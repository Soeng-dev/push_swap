
#include "../../includes/utils.h"

int		get_mid(t_data *data)
{
	int		mini;
	int		maxi;
	int		i;
	t_list	*list;

	i = *(int *)data->loaf->content;
	list = data->stack;
	mini = INT_MAX;
	maxi = INT_MIN;
	while (--i >= 0)
	{
		mini = min(*(int *)list->content, mini);
		maxi = max(*(int *)list->content, maxi);
		list = list->next;
	}
	return ((mini + maxi) / 2);
}

int		is_divided(t_list *loaf)
{
	while (loaf)
	{
		if (*(int *)loaf->content != 1)
			return (FALSE);
		loaf = loaf->next;
	}
	return (TRUE);
}

int		loaf_is_ascending(t_data *data)
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

int		loaf_is_descending(t_data *data)
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

int		is_sorted(t_input *input)
{
	t_list	*front;
	t_list	*back;

	if (ft_lstsize(input->a.loaf) == 1 && loaf_is_ascending(&input->a) &&		\
		ft_lstsize(input->b.loaf) == 0)
		return (TRUE);
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
