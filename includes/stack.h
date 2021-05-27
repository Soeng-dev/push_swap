
#ifndef STACK_H
# define STACK_H

# define ROT_FORWARD	1
# define ROT_REVERSE	-1

# include "libft/libft.h"

void	st_add(t_list **st, int n);
void	pop(t_list **st);
void	rotate(t_list **st, int dir);
void	swap(t_list *st);
void	push(t_list **from, t_list **to);

#endif
