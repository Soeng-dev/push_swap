/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:02:46 by soekim            #+#    #+#             */
/*   Updated: 2021/06/21 21:34:17 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int argc, char *argv[])
{
	t_input		input;

	ft_memset(&input, 0, sizeof(t_input));
	read_input(argc, argv, &input.a.stack);
	st_add(&input.a.loaf, argc - 1);
	if (argc <= 2)
		return (0);
	if (argc == 4 && is_sorted(&input) == FALSE)
		sort3(&input);
	else if (argc == 6 && is_sorted(&input) == FALSE)
		sort5(&input);
	else
		sort(&input);
	return (0);
}
