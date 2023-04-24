/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:36:40 by abasante          #+#    #+#             */
/*   Updated: 2023/04/24 11:22:17 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nInvalid file\n");
		exit(1);
	}
	return (fd);
}

t_count	new_counter(void)
{
	t_count	counter;

	counter.collectible = 0;
	counter.start = 0;
	counter.exit = 0;
	counter.movements = 0;
	counter.empty = 0;
	return (counter);
}

// int	len_map_validation(char **map, t_game *game)
// {
// 	line_validation(map, game);
// 	return (ft_strlen(map[0]));
// }

int	line_validation(char **map, t_game *game)
{
	int		i;
	t_point	point;

	i = 0;
	point.x = 0;
	point.y = ft_strlen(map[0]);
	while (map[i] != 0)
	{
		point.x = ft_strlen(map[i]);
		if (point.x != point.y)
		{
			free_map(game);
			endgame("Invalid file: lines are not the same size!", game, error);
		}
		i++;
	}
	return (ft_strlen(map[0]));
}

t_point	find_p(t_game *game)
{
	t_point	cord;

	cord.y = 0;
	while (game->plot.map[cord.y])
	{
		cord.x = 0;
		while (game->plot.map[cord.y][cord.x])
		{
			if (game->plot.map[cord.y][cord.x] == 'P')
			{
				return (cord);
			}
			cord.x++;
		}
		cord.y++;
	}
	return (cord);
}

void	check_if_possible(t_game *game)
{
	t_point	a;
	int		x;
	int		y;

	a.y = 0;
	a.x = 0;
	a = find_p(game);
	x = a.x;
	y = a.y;
	paint_floor(game, x, y);
	map_possible(game);
}
