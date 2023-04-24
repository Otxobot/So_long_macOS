/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:36:35 by abasante          #+#    #+#             */
/*   Updated: 2023/04/24 11:22:17 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_surrounded_by_wall(t_game *game, int y, int x)
{
	if ((game->plot.map[game->plot.height - 1][x] != '1') \
	|| (game->plot.map[0][x] != '1') \
	|| (game->plot.map[y][game->plot.length - 1] != '1') \
	|| (game->plot.map[y][0] != '1'))
	{
		return (false);
	}
	return (true);
}

bool	is_rectangular(t_game *game)
{
	if (game->plot.height == game->plot.length)
	{
		return (false);
	}
	return (true);
}

bool	is_valid_character(t_game *game, int y, int x)
{
	if (!(ft_strchr("01CEP", game->plot.map[y][x])))
	{
		return (false);
	}
	return (true);
}

bool	is_double_line(char *string_map, int i)
{
	return ((string_map[i] == '\n') && (ft_strchr("\n\0", string_map[i + 1])));
}

void	is_elements_number_valid(t_game *game, t_count *cnt, char *temp)
{
	if (!(cnt->collectible > 0 && \
	cnt->exit == 1 && cnt->start == 1 && cnt->empty > 0))
	{
		free(temp);
		endgame("Invalid, file!", game, file_error);
	}
}
