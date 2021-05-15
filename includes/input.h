
#ifndef INPUT_H
# define INPUT_H

# define TRUE	1
# define FALSE	0

# include "libft/libft.h"
# include "stack.h"

void	pass_charset(char **str, const char *set);
int		read_int(char *s, int *is_error);
void	read_input(char **input, t_list **st);

#endif
