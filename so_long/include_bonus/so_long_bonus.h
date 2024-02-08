#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// my header files
# include "structures_bonus.h"
# include "constants_bonus.h"
# include "../libft/include/libft.h"
// mlx header files
# include <mlx.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
// c header files
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>

/* ************************************************************************** */
// initialize data and graphics

int		init_data(t_data *data);
// (init_data_bonus.c)

int		init_memory(t_data *data);
// (init_data_memory_bonus.c)

int		check_map(char *map_filename, t_data *data);
// (check_map_bonus.c)

int		set_game_data(t_data *data, int map_fd);
// (set_game_data_bonus.c)

int		check_path(t_game_data *game_d);
// (check_map_path_bonus.c)

int		init_graphics(t_data *data);
// (init_graphics_bonus.c)
/* ************************************************************************** */

/* ************************************************************************** */
// display the map, or parts of it

void	display_tile(t_data *data, int row, int col);
void	display_map(t_data *data);
// (display_map_bonus.c)
/* ************************************************************************** */

/* ************************************************************************** */
// game logic and event handling

void	refresh_screen(t_data *data);
void	handle_keypress(int keycode, void *data_ptr);
void	handle_destroy(void *data_ptr);
// (handle_events_bonus.c)

void	end_game(t_data *data, char *msg);
void	move_player(t_data *data, int dx, int dy);
// (game_logic_bonus.c)
/* ************************************************************************** */

/* ************************************************************************** */
// error handling and memory management

void	clean_up(t_data *data);
// (clean_up_bonus.c)

void	err_msg(char *msg);
// (errors_bonus.c)
/* ************************************************************************** */

#endif