/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:24:22 by soekim            #+#    #+#             */
/*   Updated: 2021/06/16 11:24:52 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	st_add(t_list **st, int n)
{
	t_list	*new;
	int		*num;

	if (!st)
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

void	st_add_last(t_list **st, int n)
{
	t_list	*new;
	int		*num;

	if (!st)
		return ;
	num = (int *)malloc(sizeof(int));
	if (!num)
		return ;
	*num = n;
	new = ft_lstnew((void *)num);
	ft_lstadd_back(st, new);
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
