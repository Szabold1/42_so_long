/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:20:47 by bszabo            #+#    #+#             */
/*   Updated: 2024/01/26 11:20:53 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// my header files
# include "structures.h"
# include "constants.h"
# include "../libft/include/libft.h"
// mlx header files
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
// c header files
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>

/* ************************************************************************** */
// initialize data and graphics

int		init_data(t_data *data);
// (init_data.c)

int		init_memory(t_data *data);
// (init_data_memory.c)

int		check_map(char *map_filename, t_data *data);
// (check_map.c)

int		set_game_data(t_data *data, int map_fd);
// (set_game_data.c)

int		check_path(t_game_data *game_d);
// (check_map_path.c)

int		init_graphics(t_data *data);
// (init_graphics.c)
/* ************************************************************************** */

/* ************************************************************************** */
// display the map, or parts of it

void	display_tile(t_data *data, int row, int col);
void	display_map(t_data *data);
// (display_map.c)
/* ************************************************************************** */

/* ************************************************************************** */
// game logic and event handling

int 	handle_keypress(int keycode, void *data_ptr);
int	    handle_destroy(void *data_ptr);
// (handle_events.c)

void	end_game(t_data *data, char *msg);
void	move_player(t_data *data, int dx, int dy);
// (game_logic.c)
/* ************************************************************************** */

/* ************************************************************************** */
// error handling and memory management

void	clean_up(t_data *data);
// (clean_up.c)

void	free_array(char **array);
void	free_img(t_data *data, t_img *img);
// (clean_up_2.c)

void	err_msg(char *msg);
// (errors.c)
/* ************************************************************************** */

#endif
