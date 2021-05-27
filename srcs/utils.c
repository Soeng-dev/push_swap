
#include "../includes/utils.h"

int		min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	pass_charset(char **str, const char *set)
{
	if (!str || !(*str))
		return ;
	while (**str)
	{
		if (is_element(set, **str))
			(*str)++;
		else
			return ;
	}
	return ;
}

int		get_mid(t_data *target)
{
	int		mini;
	int		maxi;
	int		i;
	t_list	*list;

	i = *(int *)target->loaf->content;
	list = target->stack;
	while (--i >= 0)
	{
		mini = min(*(int *)i->content, mini);
		maxi = max(*(int *)i->content, mini);
		list = list->next;
	}
	return ((mini + maxi) / 2);
}
