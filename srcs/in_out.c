/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:53:16 by soekim            #+#    #+#             */
/*   Updated: 2021/05/16 20:08:50 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/in_out.h"

int		read_int(char *s, int *is_error)
{
	long int	n;

	n = 0;
	pass_charset(&s, " \t\f");
	n = ft_atoi(s);
	if (n > (long int)INT_MAX || n < (long int)INT_MIN)
		*is_error = TRUE;
	if (*s == '-')
		++s;
	if (ft_isdigit(*s) == FALSE)
		*is_error = TRUE;
	pass_charset(&s, "0123456789");
	if (*s)
		*is_error = TRUE;
	return (n);
}

void	read_input(char **input, t_list **st)
{
	int		is_error;
	t_list	*temp;

	is_error = FALSE;
	while (*input)
	{
		st_add(st, read_int(*input, &is_error));
		input++;
		temp = (*st)->next;
		while (temp)
		{
			if (*(int*)(*st)->content = *(int*)temp->content)
				is_error = TRUE;
			temp = temp->next;
		}
	}
	if (is_error)
	{
		ft_lstclear(st, free);
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
	return ;
}

void	print_stacks(t_list *st_a, t_list *st_b)
{
	int		len_a;
	int		len_b;

	len_a = ft_lstsize(st_a);
	len_b = ft_lstsize(st_b);
	ft_putchar_fd('\n', 1);
	if (len_a > len_b)
	{
		while (len_a > len_b)
		{
			ft_putnbr_fd(*(int *)st_a->content, 1);
			ft_putchar_fd('\n', 1);
			st_a = st_a->next;
			--len_a;
		}
	}
	else if (len_b > len_a)
	{
		while (len_b > len_a)
		{
			ft_putstr_fd("\t\t\t\t", 1);
			ft_putnbr_fd(*(int *)st_b->content, 1);
			ft_putchar_fd('\n', 1);
			st_b = st_b->next;
			--len_b;
		}
	}
	while (--len_a >= 0)
	{
		ft_putnbr_fd(*(int *)st_a->content, 1);
		ft_putstr_fd("\t\t\t\t", 1);
		ft_putnbr_fd(*(int *)st_b->content, 1);
		ft_putchar_fd('\n', 1);
		st_a = st_a->next;
		st_b = st_b->next;
	}
	ft_putstr_fd("----\t\t\t\t----\n", 1);
	ft_putstr_fd("a\t\t\t\tb\n\n", 1);
	return ;
}

