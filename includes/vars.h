/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:09:22 by soekim            #+#    #+#             */
/*   Updated: 2021/06/01 15:34:46 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# define TRUE	1
# define FALSE	0

# include "libft/libft.h"

#include <stdio.h>		//test

struct	s_data
{
	t_list	*stack;
	t_list	*loaf;
};
typedef struct s_data		t_data;

struct	s_input
{
	t_data	a;
	t_data	b;
};
typedef struct s_input		t_input;

struct s_move
{
	int		count;
	int		(*rule)(int, int);
	void	(*func)(void *, t_input *);
};
typedef struct s_move		t_move;

struct	s_target
{
	char	name;
	t_data	*data;
};
typedef struct s_target		t_target;

struct s_sort_info
{
	t_move		move;
	t_target	orig;
	t_target	dest;
	int			pivot;
};
typedef struct s_sort_info	t_sort_info;

#endif
