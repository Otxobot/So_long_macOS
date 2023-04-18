#ifndef UTILS_H
# define UTILS_H

# define KEYUP		13
# define KEYDOWN	1
# define KEYLEFT	0
# define KEYRIGHT	2
# define ARROWUP 126
# define ARROWDOWN	125
# define ARROWLEFT	123
# define ARROWRIGHT	124
# define ESC	53
# define WINDOW_NAME	"So_long 2D game"
# define SPRITE_SIZE	32

# define KEY_RELEASE	3
# define DESTROY_NOTIFY	17
# define EXPOSE		12

# define KEY_RELEASE_MASK	2
# define NO_EVENT_MASK		0
# define EXPOSURE_MASK		32768

enum e_direction
{
	down = 0,
	left = 1,
	right = 2,
	up = 3,
};

enum e_state
{
	event_ending = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
};

typedef struct s_counter
{
	int		empty;
	int		collectible;
	int		exit;
	int		start;
	int		movements;
}			t_counter;

typedef struct s_img
{
	void	*ptr;
	int		*pixels;
	int		line_size;
	int		mem;
	int		x;
	int		y;
	int		movements;
}			t_img;

typedef struct s_map
{
	char	**map;
	int		height;
	int		length;
	char	*line;
}			t_map;

typedef struct s_game
{
	void		*mlx_pointer;
	void 		*mlx_win;
	t_counter	i;
	t_map		plot;
	t_img		character;
	t_img		character_l;
	t_img		character_r;
	t_img		character_u;
	t_img		floor;
	t_img		wall;
	t_img		collect;
	t_img		portal;
}				t_game;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

#endif