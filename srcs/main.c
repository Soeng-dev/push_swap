/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:02:46 by soekim            #+#    #+#             */
/*   Updated: 2021/05/29 16:58:55 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/libft/libft.h"
#include "../includes/in_out.h"
#include "../includes/stack.h"
#include "../includes/command.h"

//check when one arg passed
int		main(int argc, char *argv[])
{
	t_list		*st_a;
	t_list		*st_b;

	if (argc <= 2)
		return (0);
	st_a = NULL;
	st_b = NULL;
	read_input(argv + 1, &st_a);
	print_stacks(st_a, st_b);
	
	cmd_p('b', &st_a, &st_b);
	cmd_p('b', &st_a, &st_b);
	cmd_p('b', &st_a, &st_b);

	print_stacks(st_a, st_b);
	cmd_rr('a', &st_a, &st_b);

	print_stacks(st_a, st_b);

	cmd_rr('b', &st_a, &st_b);

	print_stacks(st_a, st_b);


	cmd_rr('r', &st_a, &st_b);

	print_stacks(st_a, st_b);



	return (0);
}
