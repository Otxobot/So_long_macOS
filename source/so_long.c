/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:58:23 by abasante          #+#    #+#             */
/*   Updated: 2023/04/24 10:51:22 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void	init_game(t_game *game, char *path);
// static bool	check_ber_file(const char *argv);
// static void	init_hook(t_game *game, int event, int mask, int (*f)());

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2 && (check_ber_file(av[1])))
	{
		init_game(&game, av[1]);
	}
	else if (ac == 2 && !(check_ber_file(av[1])))
		endgame("Can't open file. The format is not supported!", &game, error);
	else if (ac > 2)
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
	init_hook (game, KEY_RELEASE, 1L << 0, key_check);
	init_hook (game, DESTROY_NOTIFY, 0L, red_cross);
	init_hook (game, EXPOSE, 1L << 15, mini_maker);
	mlx_loop(game->mlx_pointer);
}

bool	check_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
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
