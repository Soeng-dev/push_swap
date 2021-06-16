/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:21:42 by soekim            #+#    #+#             */
/*   Updated: 2021/06/16 11:25:01 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

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
