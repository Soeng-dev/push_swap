
#include "../includes/command.h"

void	cmd_s(char target, t_list **st_a, t_list **st_b)
{
	if (target == 'a')
	{
		swap(*st_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (target == 'b')
	{
		swap(*st_b);
		ft_putstr_fd("sb\n", 1);
	}
	else if (target == 's')
	{
		swap(*st_a);
		swap(*st_b);
		ft_putstr_fd("ss\n", 1);
	}
	return ;
}

void	cmd_p(char target, t_list **st_a, t_list **st_b)
{
	if (target == 'a')
	{
		push(st_a, st_b);
		ft_putstr_fd("pa\n", 1);
	}
	else if (target == 'b')
	{
		push(st_b, st_a);
		ft_putstr_fd("pb\n", 1);
	}
	return ;
}

void	cmd_r(char target, t_list **st_a, t_list **st_b)
{
	if (target == 'a')
	{
		rotate(st_a, ROT_FORWARD);
		ft_putstr_fd("ra\n", 1);
	}
	else if (target == 'b')
	{
		rotate(st_b, ROT_FORWARD);
		ft_putstr_fd("rb\n", 1);
	}
	else if (target == 'r')
	{
		rotate(st_a, ROT_FORWARD);
		rotate(st_b, ROT_FORWARD);
		ft_putstr_fd("rr\n", 1);
	}
	return ;
}

void	cmd_rr(char target, t_list **st_a, t_list **st_b)
{
	if (target == 'a')
	{
		rotate(st_a, ROT_REVERSE);
		ft_putstr_fd("rra\n", 1);
	}
	else if (target == 'b')
	{
		rotate(st_b, ROT_REVERSE);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (target == 'r')
	{
		rotate(st_a, ROT_REVERSE);
		rotate(st_b, ROT_REVERSE);
		ft_putstr_fd("rrr\n", 1);
	}
	return ;
}
