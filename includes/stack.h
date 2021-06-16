/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:22:46 by soekim            #+#    #+#             */
/*   Updated: 2021/06/16 13:22:48 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define ROT_FORWARD	1
# define ROT_REVERSE	-1

# include <stdlib.h>

# include "libft/libft.h"
# include "in_out.h"

/*
**		general
*/
void	st_add(t_list **st, int n);
void	st_add_last(t_list **st, int n);
void	pop(t_list **st);

/*
**		adhoc
*/
void	rotate(t_list **st, int dir);
void	swap(t_list *st);
void	push(t_list **from, t_list **to);

#endif
