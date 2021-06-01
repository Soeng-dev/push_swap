
#ifndef IN_OUT_H
# define IN_OUT_H

# define TRUE	1
# define FALSE	0

# include <limits.h>

# include "libft/libft.h"
# include "stack.h"
# include "utils.h"

int		read_int(char *s, int *is_error);
void	read_input(char **argv, t_list **st);
void	print_stacks(t_list *st_a, t_list *st_b);
void	print_loaf(t_list *loaf);

#endif
