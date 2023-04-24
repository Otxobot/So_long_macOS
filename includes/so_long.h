/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:37:27 by abasante          #+#    #+#             */
/*   Updated: 2023/04/24 11:22:17 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "utils.h"

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include <fcntl.h>//open, O_RDONLY
# include <unistd.h>//read, close, write
# include <stdlib.h>//malloc
# include <stdio.h>//printf
# include <stdbool.h>//bool

//so_long.c
void	init_game(t_game *game, char *path);
bool	check_ber_file(const char *argv);
void	init_hook(t_game *game, int event, int mask, int (*f)());

void	render_map(t_game	*game);
void	init_map(t_game *game, char *path);

int		key_check(int keycode, t_game *game);
void	print_moves(t_game *game);

void	move_right(t_game *parameter);
void	move_left(t_game *parameter);
void	move_up(t_game *parameter);
void	move_down(t_game *parameter);

void	player_init(t_game	*game);
//int			len_map_validation(char **map, t_game *game);
int		line_validation(char **map, t_game *game);

void	init_window(t_game *game);
void	init_images(t_game	*game);
t_img	new_sprite(void *mlx, char *path);
void	destroy_image(t_game *game);
void	free_map(t_game	*game);

int		red_cross(t_game *game);
int		mini_maker(t_game *game);
void	endgame(char *message, t_game *game, enum e_state i);

t_point	get_screen_size(t_game *game);
bool	is_larger_than_window(t_game *game);

bool	is_surrounded_by_wall(t_game *game, int y, int x);
bool	is_rectangular(t_game *game);
bool	is_valid_character(t_game *game, int y, int x);
bool	is_double_line(char *string_map, int i);
void	is_elements_number_valid( \
t_game *game, t_count *cnt, char *temp);
int		paint_floor(t_game *game, int x, int y);
t_point	find_p(t_game *game);
void	check_if_possible(t_game *game);
int		map_possible(t_game *game);

int		open_file(char *path);
t_count	new_counter(void);
#endif