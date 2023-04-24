/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:36:07 by abasante          #+#    #+#             */
/*   Updated: 2023/04/24 11:33:49 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static bool	is_down_wall(t_game *game);
static void	check_down(t_game *game);

void	move_down(t_game *game)
{
	check_down(game);
	game->character.mem = down;
	mlx_put_image_to_window(game->mlx_pointer, game->mlx_win,
		game->character.ptr, game->character.x, game->character.y);
	return ;
}

static void	check_down(t_game *game)
{
	if (game->character.y < \
	((game->plot.height * SPRITE_SIZE) - (SPRITE_SIZE * 2)))
	{
		if (!is_down_wall(game))
		{
			game->character.y += SPRITE_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_down_wall(t_game *game)
{
	return (! \
	(game->plot.map \
	[((game->character.y + SPRITE_SIZE) / SPRITE_SIZE)] \
	[(game->character.x / SPRITE_SIZE)] != '1') \
	);
}
