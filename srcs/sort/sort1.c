
#include "../../includes/sort.h"

static void	count_rotate(t_list *target, int *count_r)
{
	int		count;

	count = 0;
	*count_r = 0;
	while (target)
	{
		if (*(int *)target->content > pivot)
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
		if (*(int *)target->content > pivot)
			break;
		--count_rr;
		target = target->next;
	}
	i = *(int*)info->from->loaf->content;
	target = info->from->stack;
	while (--i >= 0)
	{
		if (*(int *)target->content > pivot)
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
	if (count_r <= count_rr)
		info->divide.func = divide_by_r;
	else
		info->divide.func = divide_by_rr;
	info->divide.count = min(count_r, count_rr);
}

void		divide_by_r(t_sort_info *info, t_input *input, char target)
{
	int		i;

	i = info->divide.count;
	while (--i >= 0)
	{
		if (info->from->stack->content > info->pivot)
			cmd_p('b', &input->a.stack, &input->b.stack);
		else
			cmd_r('a', &input->a.stack, &input->b.stack);
	}
	*(int *)input.a.stack->content = ft_lstsize(input.a.stack);
	st_add(&input->b.loaf, 				\
			ft_lstsize(input.b.stack));
	return ;
}

void		divide_by_rr(t_sort_info *info, t_input *input, char target)
{
	int		i;

	i = info->divide.count;
	while (--i >= 0)
	{
		cmd_rr(

void		sort_loaf(int from_to, t_input *input)
{
	t_sort_info		info;
	int				i;

	set_sort_info(&info, input, from_to);
	if (input.a.loaf.content == 2)
	{
		cmd_s('a', &input->a.stack, &input->b.stack);
		*(int *)input->a.loaf->content = 1;
		rotate(&input->a.loaf, ROT_FORWARD);
		st_add(&input->a.loaf, 1);
		rotate(&input->a.loaf, ROT_FORWARD);
	}
	else if (input.a.loaf.content > 2)
		info->divide.func;
}

void		sort
{
	while
	{
		if (input->a.loaf->content >= 2)
			sort_loaf;
		else
			rotate(a.loaf)
	}
}


