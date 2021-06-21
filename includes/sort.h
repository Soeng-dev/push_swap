/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:18:30 by soekim            #+#    #+#             */
/*   Updated: 2021/06/21 20:35:45 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# define A_TO_B	0
# define B_TO_A	1

# include "vars.h"
# include "utils.h"
# include "command.h"
# include "in_out.h"

/*
**		set sort
*/
int		count_mincmd(t_sort_info *info);
void	set_target(t_sort_info *info, t_input *input, int from_to);
void	set_sort_info(t_sort_info *info, t_input *input, int from_to);

/*
**		loaf
*/
void	move_by_rule(void *sort_info, t_input *input);
void	rotate_loaf(char target, t_input *input);
void	move_loaf(t_input *input, int from_to);
void	divide_move(t_sort_info *info, t_input *input, int from_to);

/*
**		sort
*/
void	sort_directly(t_input *input, int from_to);
void	sort3_to_a(t_input *input, int from_to);
void	sort(t_input *input);

/*
**		small
*/
void	sort3(t_input *input);
void	sort5(t_input *input);

#endif
