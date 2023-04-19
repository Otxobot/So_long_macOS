/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:36:54 by abasante          #+#    #+#             */
/*   Updated: 2023/04/19 16:09:00 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

static void	check_map_maker(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'E')
	{
		game->portal.x = x * SPRITE_SIZE;
		game->portal.y = y * SPRITE_SIZE;
		mlx_put_image_to_window(game->mlx_pointer, game->mlx_win, \
		game->portal.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	}
	else if (game->plot.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_pointer, game->mlx_win, \
		game->wall.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else if (game->plot.map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_pointer, game->mlx_win, \
		game->collect.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	}
	else
		mlx_put_image_to_window(game->mlx_pointer, game->mlx_win, \
		game->floor.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
}

static void	map_check_one(t_game *game, int y, int x)
{
	if (!is_surrounded_by_wall(game, y, x))
		endgame("The map is not surrounded by a wall!", game, map_char_error);
	else if (!is_rectangular(game))
		endgame("The map is not rectangular!", game, map_char_error);
	else if (!is_valid_character(game, y, x))
		endgame("Invalid character in map", game, map_char_error);
	check_map_maker(game, y, x);
	return ;
}

// int		paint_floor(t_game *game, int x, int y)
// {
// 	char	*c;
// 	char	*s;

// 	s = "C0E";
// 	c = &game->plot.map[y][x];
// 	if (*c == '0')
// 		*c = 'X';
// 	// if (*c == 'E')
// 	// 	return (*c = *c + 32, 0);
// 	if (*c == 'C')
// 		*c = *c + 32;
// 	if (y < game->plot.height / 32 - 1 && ft_strchr(s, game->plot.map[y + 1][x]) != 0)
// 		paint_floor(game, x, y + 1);
// 	if (y > 0 && game->plot.map[y - 1][x] && ft_strchr(s, game->plot.map[y - 1][x]) != 0)
// 		paint_floor(game, x, y - 1);
// 	if (x < game->plot.length / 32 - 1 && game->plot.map[y][x + 1] &&
// 		ft_strchr(s, game->plot.map[y][x + 1]) != 0)
// 		paint_floor(game, x + 1, y);
// 	if (x > 0 && game->plot.map[y][x - 1] && ft_strchr(s, game->plot.map[y][x - 1]) != 0)
// 		paint_floor(game, x - 1, y);
// 	return (0);
// }

void	render_map(t_game *game)
{
	t_point	coord;
	
	coord.y = 0;
	while (game->plot.map[coord.y])
	{
		coord.x = 0;
		while (game->plot.map[coord.y][coord.x])
		{
			//printf("game->plot.map: %c\n", game->plot.map[coord.y][coord.x]);
			map_check_one(game, coord.y, coord.x);
			coord.x++;
		}
		coord.y++;
	}
	return ;
}



// void	useit(t_game *game)
// {
// 	t_point		a;
// 	int			x;
// 	int 		y;

// 	x = a.x;
// 	y = a.y;

// 	paint_floor(game, x, y);
// 	printf("%s\n", game->plot.map[0]);
// 	printf("%s\n", game->plot.map[1]);
// 	printf("%s\n", game->plot.map[2]);
// 	printf("%s\n", game->plot.map[3]);
// }