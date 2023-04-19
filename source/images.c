/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:24:36 by abasante          #+#    #+#             */
/*   Updated: 2023/04/19 09:59:03 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/path.h"

void	init_window(t_game *game)
{
	game->mlx_pointer = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_pointer, (game->plot.length * SPRITE_SIZE), (game->plot.height * SPRITE_SIZE), WINDOW_NAME);
}

void	init_images(t_game	*game)
{
	game->wall = new_sprite(game->mlx_pointer, WALL_PATH);
	game->floor = new_sprite(game->mlx_pointer, FLOOR_PATH);
	game->collect = new_sprite(game->mlx_pointer, COLLECT_PATH);
	game->portal = new_sprite(game->mlx_pointer, PORTAL_PATH);
	game->character = new_sprite(game->mlx_pointer, CHAR_I_PATH);
	game->character_l = new_sprite(game->mlx_pointer, CHAR_L_PATH);
	game->character_r = new_sprite(game->mlx_pointer, CHAR_R_PATH);
	game->character_u = new_sprite(game->mlx_pointer, CHAR_U_PATH);
	return ;
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}
