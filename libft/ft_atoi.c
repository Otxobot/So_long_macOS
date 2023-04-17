
#include "libft.h"

static void	jump_spaces(int *number, const char *str);

int	ft_atoi(const char *str)
{
	long	number;
	int		sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	jump_spaces(&i, str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
		if (number > MAX_INT && sign == POSITIVE)
			return (-1);
		if (number > MIN_INT && sign == NEGATIVE)
			return (0);
	}
	return (sign * (int)number);
}

static void	jump_spaces(int *number, const char *str)
{
	while (ft_isspace(str[*number]))
		(*number)++;
}
