
void	rotate_and_move(t_sort_info *sort							\
						void (*rotate)(char, t_list **, t_list **))
{
	
	return ;
}

void	count_rotate(t_list *target, int *count_r, int *count_rr)
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
	count_rr = ft_lstsize(*from) + 1;
	while (target)
	{
		if (*(int *)target->content <= pivot)
			break;
		--count_rr;
		target = target->next;
	}
	return ;
}

void	set_rotate(t_rotate *rot, t_list *target)
{
	int			count_r;
	int			count_rr;

	count_rotate(target, &count_r, &count_rr);
	if (count_r < count_rr)
	{
		rot->count = count_r;
		rot->func = cmd_r;
	}
	else
	{
		rot->count = count_rr;
		rot->func = cmd_rr;
	}
	return ;
}

void	move_small(t_list **to, t_list **from)
{
	t_sort_info	sort;

	ft_memset(&sort, 0, sizeof(t_sort_info));
	sort.pivot = get_mid(*from);
	set_rotate(&sort.rotate, *from);
	
}
