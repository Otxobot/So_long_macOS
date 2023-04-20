/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:43:38 by abasante          #+#    #+#             */
/*   Updated: 2023/04/20 11:43:39 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	len;

	if (s == 0)
		return (NULL);
	len = ft_strlen(s);
	string = (char *)malloc(len + 1);
	if (!string)
		return (NULL);
	string[len] = '\0';
	while (len)
	{
		string[len - 1] = f(len - 1, s[len - 1]);
		len--;
	}
	return (string);
}
