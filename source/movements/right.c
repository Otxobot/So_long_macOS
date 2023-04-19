/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:36:20 by abasante          #+#    #+#             */
/*   Updated: 2023/04/19 09:36:21 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"

static bool	is_right_wall(t_game *game);
static void	check_right(t_game *game);

void	move_right(t_game *game)
{
	check_right(game);
	game->character.mem = right;
	mlx_put_image_to_window(game->mlx_pointer, game->mlx_win,
		game->character_r.ptr, game->character.x, game->character.y);
	return ;
}

static void	check_right(t_game *game)
{
	if (game->character.x < \
	((game->plot.length * SPRITE_SIZE) - (SPRITE_SIZE * 2)))
	{
		if (!is_right_wall(game))
		{
			game->character.x += SPRITE_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_right_wall(t_game *game)
{
	return (! \
	(game->plot.map \
	[(game->character.y / SPRITE_SIZE)] \
	[((game->character.x + SPRITE_SIZE) / SPRITE_SIZE)] != '1') \
	);
}
