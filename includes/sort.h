
#ifndef SORT_H
# define SORT_H

# define A_TO_B	0
# define B_TO_A	1

# include "vars.h"
# include "utils.h"
# include "command.h"

void	set_sort_info(t_sort_info *info, t_input *input, int from_to);
void	move_by_r(void *sort_info, t_input *input);
void	move_by_rr(void *sort_info, t_input *input);
void	divide_loaf(t_sort_info *info, t_input *input, int from_to);
void	sort(t_input *input);

#endif
