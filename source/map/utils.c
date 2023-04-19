/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:36:40 by abasante          #+#    #+#             */
/*   Updated: 2023/04/19 16:46:18 by abasante         ###   ########.fr       */
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

t_counter	new_counter(void)
{
	t_counter	counter;

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
		while(game->plot.map[cord.y][cord.x])
		{

			if (game->plot.map[cord.y][cord.x] == 'P')
			{
				printf("%d\n", cord.x);
				printf("%d\n", cord.y);
				return(cord);
			}
			cord.x++;
		}
		cord.y++;
	}
	return (cord);
}

void		check_if_possible(t_game *game)
{
	t_point	a;
	a.y = 	0;
	a.x = 	0;
	int		x;
	int 	y;

	a = find_p(game);
	x = a.x;
	y = a.y;

	printf("x:%d\n", x);
	printf("y:%d\n", y);

	printf("%s\n", game->plot.mapcopy[0]);
	printf("%s\n", game->plot.mapcopy[1]);
	printf("%s\n", game->plot.mapcopy[2]);
	printf("%s\n", game->plot.mapcopy[3]);
	printf("----------------------------\n");
	paint_floor(game, x, y);
	printf("%s\n", game->plot.mapcopy[0]);
	printf("%s\n", game->plot.mapcopy[1]);
	printf("%s\n", game->plot.mapcopy[2]);
	printf("%s\n", game->plot.mapcopy[3]);
}

int	paint_floor(t_game *game, int x, int y)
{
	char	*c;
	char	*s;

	s = "C0E";
	c = &game->plot.mapcopy[y][x];
	if (*c == '0')
		*c = 'X';
	if (*c == 'E')
		return (*c = *c + 32, 0);
	if (*c == 'C' || *c == 'H' || *c == 'V')
		*c = *c + 32;
	if (y < game->plot.height - 1 && ft_strchr(s, game->plot.mapcopy[y + 1][x]) != 0)
	{
		paint_floor(game, x, y + 1);
	}
	if (y > 0 && game->plot.mapcopy[y - 1][x] && ft_strchr(s, game->plot.mapcopy[y - 1][x]) != 0)
	{
		paint_floor(game, x, y - 1);
	}	
	if (x < game->plot.length - 1 && game->plot.mapcopy[y][x + 1] && \
		ft_strchr(s, game->plot.mapcopy[y][x + 1]) != 0)
	{
		paint_floor(game, x + 1, y);
	}
	if (x > 0 && game->plot.mapcopy[y][x - 1] && ft_strchr(s, game->plot.mapcopy[y][x - 1]) != 0)
	{
		paint_floor(game, x - 1, y);
	}
	return (0);
}