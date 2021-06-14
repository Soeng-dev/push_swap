
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
