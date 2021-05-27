
#ifndef SORT_H
# define SORT_H
# define A_TO_B	0
# define B_TO_A	1

struct	s_data
{
	t_list	*stack;
	t_list	*loaf;
};
typedef struct s_data		t_data;

struct	s_input
{
	t_data	a;
	t_data	b;
};
typedef struct s_input		t_input;

struct s_divide
{
	int		count;
	void	*func(char , t_list **, t_list **);
};
typedef struct s_divide		t_divide;

struct s_sort_info
{
	t_divide	divide;
	t_data		*from;
	t_data		*to;
	int			pivot;
};
typedef struct s_sort_info	t_sort_info;

/*
**		
*/
void	count_rotate(t_list *target, int *count_r);
void	count_revrot(t_list *target, int *count_rr);
void	set_sort_info(t_sort_info *info, t_list *target);

#endif
