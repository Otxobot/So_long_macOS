
#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int	size_of_list;

	size_of_list = 0;
	while (list)
	{
		list = list->next;
		size_of_list++;
	}
	return (size_of_list);
}
