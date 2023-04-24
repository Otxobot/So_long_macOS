/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:43:18 by abasante          #+#    #+#             */
/*   Updated: 2023/04/24 11:29:09 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtjoin(char *string0, char *string1, char *string2)
{
	char	*str;
	char	*temp_string;

	if (!string0 | !string1 | !string2)
		return (NULL);
	temp_string = ft_strjoin(string0, string1);
	str = ft_strjoin(temp_string, string2);
	free(temp_string);
	temp_string = NULL;
	return (str);
}
