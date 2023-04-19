/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:35:55 by abasante          #+#    #+#             */
/*   Updated: 2023/04/19 09:59:58 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	red_cross(t_game *game)
{
	endgame("", game, event_ending);
	return (0);
}

int	mini_maker(t_game *game)
{
	render_map(game);
	if (game->i.movements == 0)
		player_init(game);
	else if (game->character.mem == down)
		mlx_put_image_to_window(game->mlx_pointer, game->mlx_win, game->character.ptr, game->character.x, game->character.y);
	else if (game->character.mem == left)
		mlx_put_image_to_window(game->mlx_pointer, game->mlx_win, game->character_l.ptr, game->character.x, game->character.y);
	else if (game->character.mem == right)
		mlx_put_image_to_window(game->mlx_pointer, game->mlx_win, game->character_r.ptr, game->character.x, game->character.y);
	else if (game->character.mem == up)
		mlx_put_image_to_window(game->mlx_pointer, game->mlx_win, game->character_u.ptr, game->character.x, game->character.y);
	return (0);
}
