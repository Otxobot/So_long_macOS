
#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*temp;

	if (*list)
	{
		temp = ft_lstlast(*list);
		temp->next = new;
	}
	else
	{
		*list = new;
	}
}
