/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:53:16 by soekim            #+#    #+#             */
/*   Updated: 2021/06/21 19:52:35 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/in_out.h"

int			read_int(char *s, int *is_error)
{
	long int	n;

	n = 0;
	pass_charset(&s, " \t\f");
	n = ft_atoi(s);
	if (n > (long int)INT_MAX || n < (long int)INT_MIN ||
		(n == 0 && *s != '0') || (n == -1 && ft_strncmp(s, "-1", ft_strlen(s))))
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

void		read_input(int argc, char **argv, t_list **st)
{
	int		is_error;

	is_error = FALSE;
	while (--argc >= 1)
	{
		++argv;
		st_add_last(st, read_int(*argv, &is_error));
	}
	if (check_duplicate(*st) == TRUE)
		is_error = TRUE;
	if (is_error)
	{
		ft_lstclear(st, free);
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
	return ;
}

static void	prt_bigger_stack(t_list *st_a, t_list *st_b, int *len_a, int *len_b)
{
	if (*len_a > *len_b)
	{
		while (*len_a > *len_b)
		{
			ft_putnbr_fd(*(int *)st_a->content, 1);
			ft_putchar_fd('\n', 1);
			st_a = st_a->next;
			--(*len_a);
		}
	}
	else if (*len_b > *len_a)
	{
		while (*len_b > *len_a)
		{
			ft_putstr_fd("\t\t\t\t", 1);
			ft_putnbr_fd(*(int *)st_b->content, 1);
			ft_putchar_fd('\n', 1);
			st_b = st_b->next;
			--(*len_b);
		}
	}
}

void		print_stacks(t_input *input)
{
	int		len_a;
	int		len_b;
	t_list	*st_a;
	t_list	*st_b;

	st_a = input->a.stack;
	st_b = input->b.stack;
	len_a = ft_lstsize(st_a);
	len_b = ft_lstsize(st_b);
	ft_putchar_fd('\n', 1);
	prt_bigger_stack(st_a, st_b, &len_a, &len_b);
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
