/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:10:04 by soekim            #+#    #+#             */
/*   Updated: 2021/06/16 13:10:08 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_OUT_H
# define IN_OUT_H

# define TRUE	1
# define FALSE	0

# include "libft/libft.h"
# include "stack.h"
# include "utils.h"

int		read_int(char *s, int *is_error);
void	read_input(int argc, char **argv, t_list **st);
void	print_stacks(t_input *input);

#endif
