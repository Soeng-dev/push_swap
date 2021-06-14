
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
**		push_swap
*/
int		get_pivot(t_data *data);
int		is_divided(t_list *loaf);
int		loaf_is_ascending(t_data *data);
int		loaf_is_descending(t_data *data);
int		is_sorted(t_input *input);

#endif
