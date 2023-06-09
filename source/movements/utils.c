/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:36:30 by abasante          #+#    #+#             */
/*   Updated: 2023/04/24 11:35:45 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_check(int keycode, t_game *game)
{
	game->character.mem = 0;
	if (keycode == ESC)
		endgame("", game, event_ending);
	else if (keycode == KEYLEFT || keycode == ARROWLEFT)
		move_left(game);
	else if (keycode == KEYRIGHT || keycode == ARROWRIGHT)
		move_right(game);
	else if (keycode == KEYUP || keycode == ARROWUP)
		move_up(game);
	else if (keycode == KEYDOWN || keycode == ARROWDOWN)
		move_down(game);
	return (0);
}

void	print_moves(t_game *game)
{
	game->i.movements += 1;
	if (game->plot.map[game->character.y / SPRITE_SIZE] \
	[game->character.x / SPRITE_SIZE] == 'C')
	{
		game->plot.map[game->character.y / SPRITE_SIZE] \
		[game->character.x / SPRITE_SIZE] = '0';
		game->i.collectible--;
	}
	else if (game->plot.map[game->character.y / SPRITE_SIZE] \
	[game->character.x / SPRITE_SIZE] == 'E' && game->i.collectible == 0)
	{
		endgame("\n\nThe End! :)", game, game_over);
	}
	ft_putstr_fd("\rMovements: ", 1);
	ft_putnbr_fd(game->i.movements, 1);
	return ;
}
