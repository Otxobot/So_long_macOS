#include "../includes/so_long.h"

static void	render_player(t_game *game);

void	player_init(t_game	*game)
{
	t_point	point;

	point.y = 0;
	while (game->plot.map[point.y])
	{
		point.x = 0;
		while (game->plot.map[point.y][point.x])
		{
			if (game->plot.map[point.y][point.x] == 'P')
			{
				game->character.x = (SPRITE_SIZE * point.x);
				game->character.y = (SPRITE_SIZE * point.y);
				render_player(game);
				return ;
			}
			point.x++;
		}
		point.y++;
	}
	return ;
}

static void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_pointer, game->mlx_win,
	game->character.ptr, game->character.x, game->character.y);
}
