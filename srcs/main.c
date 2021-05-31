/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:02:46 by soekim            #+#    #+#             */
/*   Updated: 2021/05/31 17:32:13 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

#include <stdio.h>


//check when one arg passed
int		main(int argc, char *argv[])
{
	t_input		input;

	if (argc <= 2)
		return (0);

	ft_memset(&input, 0, sizeof(t_input));
	read_input(argv + 1, &input.a.stack);
	st_add(&input.a.loaf, argc - 1);
	print_stacks(input.a.stack, input.b.stack);


	sort(&input);
	print_stacks(input.a.stack, input.b.stack);


//	cmd_p('b', &st_a, &st_b);
//	cmd_p('b', &st_a, &st_b);
//	cmd_p('b', &st_a, &st_b);
//
//	print_stacks(st_a, st_b);
//	cmd_rr('a', &st_a, &st_b);
//
//	print_stacks(st_a, st_b);
//
//	cmd_rr('b', &st_a, &st_b);
//
//	print_stacks(st_a, st_b);
//
//
//	cmd_rr('r', &st_a, &st_b);
//
//	print_stacks(st_a, st_b);
//
	return (0);
}
