/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:10:19 by soekim            #+#    #+#             */
/*   Updated: 2021/06/16 13:10:22 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "vars.h"
# include "stack.h"
# include "libft/libft.h"

void	cmd_s(char target, t_list **st_a, t_list **st_b);
void	cmd_p(char target, t_list **st_a, t_list **st_b);
void	cmd_r(char target, t_list **st_a, t_list **st_b);
void	cmd_rr(char target, t_list **st_a, t_list **st_b);
void	cmd_repeat(t_cmd cmd, t_input *input, char target, int n);

#endif
