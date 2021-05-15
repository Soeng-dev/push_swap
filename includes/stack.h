
#ifndef STACK_H
# define STACK_H
# include "libft/libft.h"

void	st_add(t_list **st, int n);
void	rotate(t_list **st);
void	rev_rotate(t_list **st);
void	swap(t_list *st);
void	push(t_list **from, t_list **to);

#endif
