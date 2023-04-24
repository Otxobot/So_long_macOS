/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_possible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:01:09 by abasante          #+#    #+#             */
/*   Updated: 2023/04/24 11:07:38 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	map_possible(t_game *game)
{
	t_point	e;

	e.y = 0;
	e.x = 0;
	while (game->plot.mapcopy[e.y])
	{
		e.x = 0;
		while (game->plot.mapcopy[e.y][e.x])
		{
			if (game->plot.mapcopy[e.y][e.x] == 'E' || \
			game->plot.mapcopy[e.y][e.x] == 'C')
			{
				endgame("map isn't possible", game, error);
				return (0);
			}
			e.x++;
		}
		e.y++;
	}
	return (1);
}

int	paint_floor(t_game *game, int x, int y)
{
	char	*c;
	char	*s;

	s = "C0E";
	c = &game->plot.mapcopy[y][x];
	if (*c == '0')
		*c = 'X';
	if (*c == 'E')
		*c = *c + 32;
	if (*c == 'C')
		*c = *c + 32;
	if (y < game->plot.height - 1 && \
	ft_strchr(s, game->plot.mapcopy[y + 1][x]) != 0)
		paint_floor(game, x, y + 1);
	if (y > 0 && game->plot.mapcopy[y - 1][x] && \
	ft_strchr(s, game->plot.mapcopy[y - 1][x]) != 0)
		paint_floor(game, x, y - 1);
	if (x < game->plot.length - 1 && game->plot.mapcopy[y][x + 1] && \
		ft_strchr(s, game->plot.mapcopy[y][x + 1]) != 0)
		paint_floor(game, x + 1, y);
	if (x > 0 && game->plot.mapcopy[y][x - 1] && \
	ft_strchr(s, game->plot.mapcopy[y][x - 1]) != 0)
		paint_floor(game, x - 1, y);
	return (0);
}
