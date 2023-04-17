
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = (char *)dest;
	psrc = (char *)src;
	while (n)
	{
		pdest[n - 1] = psrc[n - 1];
		n--;
	}
	return (pdest);
}
