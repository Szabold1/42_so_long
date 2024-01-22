#ifndef SO_LONG_H
# define SO_LONG_H

# define CELL_SIZE 42
# define PLAYER_PATH "./textures/monkey.xpm"
# define EXIT_PATH "./textures/restroom.xpm"
# define COLLECTIBLE_PATH "./textures/banana.xpm"
# define WALL_PATH "./textures/wall.xpm"
# define GROUND_PATH "./textures/empty.xpm"

# include "../libft/include/libft.h"
// # include <mlx.h>
// #include <X11/X.h>
// #include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

// structure for holding data related to the game
typedef struct s_game_data {
	char	**map;
	int		rows;
	int		cols;
	int		collect;
	int		exit;
	int		start;
	int		player_row;
	int		player_col;
	int		moves;
}	t_game_data;

// structure for holding data related to an image
typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

// structure for holding data related to mlx (graphics)
typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img_ptr;
	t_img	*player_ptr;
	t_img	*exit_ptr;
	t_img	*collect_ptr;
	t_img	*wall_ptr;
	t_img	*ground_ptr;
}	t_data;

// File: set_game_data.c
t_game_data	*set_game_data(char *filename, t_data *data);

// File: check_map.c
bool	check_rect_walls(t_game_data *game_d, int i, int j);
bool	check_elements_path(t_game_data *game_d, int i, int j);

// File: set_graphics_data.c
t_data	*set_graphics_data(t_game_data *game_d);

// File: exit_free.c
void	exit_error(char *err_msg);
void	exit_free(t_data *data, t_game_data *game_d, char *err_msg);

#endif