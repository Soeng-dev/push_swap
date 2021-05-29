
#include "../../includes/utils.h"

int		get_mid(t_data *data)
{
	int		mini;
	int		maxi;
	int		i;
	t_list	*list;

	i = *(int *)data->loaf->content;
	list = data->stack;
	mini = INT_MAX;
	maxi = INT_MIN;
	while (--i >= 0)
	{
		mini = min(*(int *)list->content, mini);
		maxi = max(*(int *)list->content, mini);
		list = list->next;
	}
	return ((mini + maxi) / 2);
}

int		is_divided(t_list *loaf)
{
	while (loaf)
	{
		if (*(int *)loaf->content != 1)
			return (FALSE);
		loaf = loaf->next;
	}
	return (TRUE);
}
