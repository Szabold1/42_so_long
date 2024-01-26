/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:20:47 by bszabo            #+#    #+#             */
/*   Updated: 2024/01/26 11:20:53 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define CELL_SIZE 42

# define PLAYER_PATH "./textures/monkey.xpm"
# define EXIT_PATH "./textures/restroom.xpm"
# define COLLECTIBLE_PATH "./textures/banana.xpm"
# define WALL_PATH "./textures/wall.xpm"
# define GROUND_PATH "./textures/empty.xpm"

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define GROUND '0'

# define KEY_ESC 0xff1b
# define KEY_UP_ARROW 0xff52
# define KEY_DOWN_ARROW 0xff54
# define KEY_LEFT_ARROW 0xff51
# define KEY_RIGHT_ARROW 0xff53

# include "../libft/include/libft.h"
# include <mlx.h>
// # include "../../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

// structure for holding data related to the game
typedef struct s_game_data
{
	char	**map;
	int		rows;
	int		cols;
	int		collect;
	int		exit;
	int		start;
	int		player_curr_x;
	int		player_curr_y;
	int		moves;
}	t_game_data;

// structure for holding data related to an image
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

// structure for holding all data related to the game
typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img_ptr;
	t_img		*player_ptr;
	t_img		*exit_ptr;
	t_img		*collect_ptr;
	t_img		*wall_ptr;
	t_img		*ground_ptr;
	t_game_data	*game_d;
}	t_data;

// File: check_map.c
// (functions for checking the validity of the map)
bool		check_rect_walls(t_game_data *game_d, int row, int col);
bool		check_elements_path(t_game_data *game_d, int i, int j);

// File: draw.c
// (functions for drawing to the image)
void		handle_draw_cell(t_data *data, int row, int col);
void		draw_map(t_game_data *game_d, t_data *data);

// File: exit_free.c
// (functions for freeing memory and exiting the program)
void		exit_error(char *err_msg);
void		exit_free(t_data *data, char *err_msg);
void		end_game(t_data *data, char *msg);

// File: handle_events.c
int			handle_keypress(int keycode, void *param);
int			handle_destroy(void *param);

// File: move_player.c
void		move_player(t_data *data, int x, int y);

// File: set_game_data.c
t_game_data	*set_game_data(char *filename, t_data *data, t_game_data *game_d);

// File: set_graphics_data.c
t_data		*set_graphics_data(t_data *data);

#endif
