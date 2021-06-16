/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:02:46 by soekim            #+#    #+#             */
/*   Updated: 2021/06/16 12:50:36 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

int		main(int argc, char *argv[])
{
	t_input		input;

	if (argc <= 2)
		return (0);
	ft_memset(&input, 0, sizeof(t_input));
	read_input(argc, argv, &input.a.stack);
	st_add(&input.a.loaf, argc - 1);
	sort(&input);
	return (0);
}
