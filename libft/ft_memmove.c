
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = dst;
	source = (unsigned char *)src;
	if (dest <= source)
	{
		return (ft_memcpy (dst, src, len));
	}
	else
	{
		while (len--)
		{
			dest[len] = source[len];
		}
		return (dest);
	}
}
