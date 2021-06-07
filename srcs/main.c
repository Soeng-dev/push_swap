/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:02:46 by soekim            #+#    #+#             */
/*   Updated: 2021/06/07 20:26:52 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

//check when one arg passed
int		main(int argc, char *argv[])
{
	t_input		input;

	if (argc <= 2)
		return (0);

	ft_memset(&input, 0, sizeof(t_input));
	read_input(argv + 1, &input.a.stack);
	st_add(&input.a.loaf, argc - 1);
//	print_stacks(&input);
//	print_loaf(&input);

	sort(&input);
//	print_stacks(&input);
//	print_loaf(&input);


//	read_input(argv + 1, &input.b.stack);
//	st_add(&input.b.loaf, argc - 1);
//	print_stacks(&input);
//	print_loaf(&input);
//
//	sort_directly(&input, B_TO_A);
//
//	print_stacks(&input);
//	print_loaf(&input);


//	char	c;
//	while (scanf("%c", &c))
//	{
//		if (c == 'q')
//			break;
//		sort(&input);
//		print_stacks(&input);
//		print_loaf(&input);
//	}

//	// sort3 b to a
//	ft_memset(&input, 0, sizeof(t_input));
//	read_input(argv + 1, &input.b.stack);
//	st_add(&input.b.loaf, argc - 1);
//	print_stacks(&input);
//	print_loaf(&input);
//	
//	sort3_to_a(&input, B_TO_A);
//	print_stacks(&input);
//	print_loaf(&input);


	return (0);
}
