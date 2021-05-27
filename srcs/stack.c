
#include "../includes/stack.h"

void	st_add(t_list **st, int n)
{
	t_list	*new;
	int		*num;

	if (!st)
		return ;
	if (!(*st))
		return ;
	num = (int *)malloc(sizeof(int));
	if (!num)
		return ;
	*num = n;
	new = ft_lstnew((void *)num);
	ft_lstadd_front(st, new);
	*st = new;
	return ;
}

void	pop(t_list **st)
{
	t_list	*to_delete;

	if (!st)
		return ;
	if (!(*st))
		return ;
	to_delete = *st;
	*st = (*st)->next;
	ft_lstdelone(to_delete, free);
	return ;
}

void	rotate(t_list **st, int dir)
{
	t_list	*first;
	t_list	*befo_last;
	t_list	*last;

	if (!(*st) || !(*st)->next)
		return ;
	if (dir == ROT_FORWARD)
	{
		first = *st;
		*st = (*st)->next;
		first->next = NULL;
		ft_lstadd_back(st, first);
	}
	else if (dir == ROT_REVERSE)
	{
		befo_last = *st;
		while (befo_last->next->next)
			befo_last = befo_last->next;
		last = befo_last->next;
		befo_last->next = NULL;
		ft_lstadd_front(st, last);
	}
	else
		return ;
	return ;
}

void	swap(t_list *st)
{
	int		*temp;

	if (!st || !st->next)
		return ;
	temp = (int *)st->content;
	st->content = st->next->content;
	st->next->content = (void *)temp;
	return ;
}

void	push(t_list **to, t_list **from)
{
	t_list	*target;

	if (!(*from))
		return ;
	target = *from;
	*from = (*from)->next;
	target->next = *to;
	*to = target;
	return ;
}
