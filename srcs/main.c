/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:02:46 by soekim            #+#    #+#             */
/*   Updated: 2021/06/01 17:12:04 by soekim           ###   ########.fr       */
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
//	print_stacks(input.a.stack, input.b.stack);
//
//
//	sort(&input);
//	print_stacks(input.a.stack, input.b.stack);


	t_sort_info		info;

	set_sort_info(&info, &input, A_TO_B);
	printf("%d\n", info.pivot);
	if (info.move.func == move_by_r)
		printf("r	%d\n", info.move.count);
	else if (info.move.func == move_by_r)
		printf("rr	%d\n", info.move.count);
	

	return (0);
}
