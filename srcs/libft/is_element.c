
#include "libft.h"

int		is_element(const char *set, char c)
{
	if (!set)
		return (-1);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
