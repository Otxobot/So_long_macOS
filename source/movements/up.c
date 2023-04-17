#include "../../includes/so_long.h"

static bool	is_up_wall(t_game *game);
static void	check_up(t_game *game);

void	move_up(t_game *game)
{
	check_up(game);
	game->character.mem = up;
	mlx_put_image_to_window(game->mlx_pointer, game->mlx_win, game->character_u.ptr, game->character.x, game->character.y);
	return ;
}

static void	check_up(t_game *game)
{
	if ((game->character.y > SPRITE_SIZE))
	{
		if (!is_up_wall(game))
		{
			game->character.y -= SPRITE_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_up_wall(t_game *game)
{
	return (! \
	(game->plot.map \
	[((game->character.y - SPRITE_SIZE) / SPRITE_SIZE)] \
	[(game->character.x / SPRITE_SIZE)] != '1') \
	);
}
