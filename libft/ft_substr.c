/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:43:10 by abasante          #+#    #+#             */
/*   Updated: 2023/04/24 11:29:14 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check(const char *s, unsigned int start, size_t len);
static char		*start_out_of_bounds(void);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*substr;

	if (!s)
		return (NULL);
	else if (start > ft_strlen(s))
		return (start_out_of_bounds());
	substr = malloc((check(s, start, len)) * sizeof(char));
	if (!substr)
		return (NULL);
	index = 0;
	while ((len--) && (s[start + index] != '\0') && \
	((start + index) < ft_strlen(s)))
	{
		substr[index] = s[start + index];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}

static size_t	check(const char *s, unsigned int start, size_t len)
{
	const size_t	s_len = ft_strlen(s);
	size_t			size;

	size = 0;
	if (start > s_len)
	{
		size = 1;
	}
	else if (start + len > s_len)
	{
		size = s_len - start + 1;
	}
	else
	{
		size = len + 1;
	}
	return (size);
}

static char	*start_out_of_bounds(void)
{
	char	*substr;

	substr = malloc(sizeof(char));
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}
