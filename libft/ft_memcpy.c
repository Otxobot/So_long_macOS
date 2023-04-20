/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:44:48 by abasante          #+#    #+#             */
/*   Updated: 2023/04/20 11:44:49 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	char	*pdest;
// 	char	*psrc;

// 	if (!dest && !src)
// 		return (NULL);
// 	pdest = (char *)dest;
// 	psrc = (char *)src;
// 	while (n)
// 	{
// 		pdest[n - 1] = psrc[n - 1];
// 		n--;
// 	}
// 	return (pdest);
// }

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}