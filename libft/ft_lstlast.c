#include "libft.h"

t_list	*ft_lstlast(t_list *list)
{
	if (list)
	{
		while (list->next != NULL)
		{
			list = list->next;
		}
		return (list);
	}
	return (NULL);
}
