
#include "../includes/stack.h"

void	push(t_list **st, int n)
{
	t_list	*new;
	int	*num;

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

	to_delete = *st;
	*st = (*st)->next;
	ft_lstdelone(to_delete, free);
	return ;
}

void	rotate(t_list **st)
