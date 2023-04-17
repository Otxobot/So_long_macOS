
#include "../includes/so_long.h"

// static void	init_game(t_game *game, char *path);
// static bool	check_ber_file(const char *argv);
// static void	init_hook(t_game *game, int event, int mask, int (*f)());

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2 && (check_ber_file(argv[1])))
	{
		// printf("&game: %p\n", &game);
		init_game(&game, argv[1]);
	}
	else if (argc == 2 && !(check_ber_file(argv[1])))
		endgame("Can't open file. The format is not supported!", &game, error);
	else if (argc > 2)
		endgame("Can't open multiple files!", &game, error);
	else
		endgame("Please specify file name!", &game, error);
	return (0);
}

void	init_game(t_game *game, char *path)
{
	init_map(game, path);
	init_window(game);
	init_images(game);
	render_map(game);
	init_hook(game, KEY_RELEASE, KEY_RELEASE_MASK, key_check);
	init_hook(game, DESTROY_NOTIFY, NO_EVENT_MASK, red_cross);
	init_hook(game, EXPOSE, EXPOSURE_MASK, mini_maker);
	mlx_loop(game->mlx_pointer);
}

bool	check_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
	// printf("string: %s\n", string);
	if (string)
	{
		return (ft_strcmp(string, ".ber") == 0);
	}
	return (false);
}

void	init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->mlx_win, event, mask, f, game);
}
