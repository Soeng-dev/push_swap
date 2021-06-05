
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

#endif
