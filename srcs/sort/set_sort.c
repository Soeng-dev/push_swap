
#include "../../includes/sort.h"

static void	count_rotate(t_list *target, int *count_r)
{
	int		count;

	count = 0;
	*count_r = 0;
	while (target)
	{
		if (*(int *)target->content <= pivot)
			*count_r = count;
		++count;
		target = target->next;
	}
	return ;
}

static void	count_revrot(t_sort_info *info, int *count_rr)
{
	t_list	*target;
	int		i;

	target = info->from->stack;
	i = *(int*)info->from->loaf->content;
	*count_rr = ft_lstsize(target);
	while (--i >= 0)
	{
		if (*(int *)target->content <= pivot)
			break;
		--count_rr;
		target = target->next;
	}
	i = *(int*)info->from->loaf->content;
	target = info->from->stack;
	while (--i >= 0)
	{
		if (*(int *)target->content <= pivot)
			++count_rr;
		target = target->next;
	}
	return ;
}

void		set_sort_info(t_sort_info *info, t_input *input, int from_to)
{
	t_list	*from;
	int		count_r;
	int		count_rr;

	if (from_to = A_TO_B)
	{
		info->from = &input->a;
		info->to = &input->b;
	}
	else if (from_to = B_TO_A)
	{
		info->from = &input->b;
		info->to = &input->a;
	}
	info->pivot = get_mid(info->from);
	count_rotate(target, &count_r);
	count_revrot(info, &count_rr);
	if (count_rr <= count_rr && from_to = B_TO_A)
	{
		info->rot.func = cmd_rr;
		info->rot.count = min(count_r, count_rr);
	}
	else
		info->rot.func = cmd_r;
}

void		move_small(int from_to, t_input *input)
{
	t_sort_info		info;

	set_sort_info(&info, input, from_to);
	
}
