/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:36:14 by abasante          #+#    #+#             */
/*   Updated: 2023/04/19 09:36:15 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"

static bool	is_left_wall(t_game *game);
static void	check_left(t_game *game);

void	move_left(t_game *game)
{
	check_left(game);
	game->character.mem = left;
	mlx_put_image_to_window(game->mlx_pointer, game->mlx_win,
		game->character_l.ptr, game->character.x, game->character.y);
	return ;
}

static void	check_left(t_game *game)
{
	if ((game->character.x > SPRITE_SIZE))
	{
		if (!is_left_wall(game))
		{
			game->character.x -= SPRITE_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_left_wall(t_game *game)
{
	return (! \
	(game->plot.map \
	[(game->character.y / SPRITE_SIZE)] \
	[((game->character.x - SPRITE_SIZE) / SPRITE_SIZE)] != '1') \
	);
}
