/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:22:54 by soekim            #+#    #+#             */
/*   Updated: 2021/06/21 19:50:06 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <limits.h>

# include "libft/libft.h"
# include "vars.h"

/*
**		general
*/
int		min(int a, int b);
int		max(int a, int b);
void	pass_charset(char **str, const char *set);
int		is_bigger(int target, int pivot);
int		is_smaller(int target, int pivot);

/*
**		pivot
*/
int		get_pivot(t_data *data);

/*
**		status
*/
int		check_duplicate(t_list *list);
int		is_divided(t_list *loaf);
int		loaf_is_ascending(t_data *data);
int		loaf_is_descending(t_data *data);
int		is_sorted(t_input *input);

#endif
