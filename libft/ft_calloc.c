
#include "libft.h"

static int	is_overflow(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	if (count == 0 || size == 0 || is_overflow(count, size))
	{
		return (NULL);
	}
	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	return (ft_memset(pointer, 0, (count * size)));
}

static int	is_overflow(size_t count, size_t size)
{
	size_t	result;

	result = count * size;
	if (count == result / size)
	{
		return (0);
	}
	else
	{
		errno = ENOMEM;
		return (1);
	}
}
