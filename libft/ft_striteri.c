
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	index;

	if (s == 0 || f == 0)
		return ;
	index = ft_strlen(s);
	while (index)
	{
		f(index - 1, &s[index - 1]);
		index--;
	}
}
