
#ifndef COMMAND_H
# define COMMAND_H
# include "stack.h"
# include "libft/libft.h"

void	cmd_s(char target, t_list *st_a, t_list *st_b);
void	cmd_p(char target, t_list **st_a, t_list **st_b);
void	cmd_r(char target, t_list **st_a, t_list **st_b);
void	cmd_rr(char target, t_list **st_a, t_list **st_b);

#endif
