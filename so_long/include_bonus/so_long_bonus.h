/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:07:36 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:07:41 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// my header files
# include "structures_bonus.h"
# include "constants_bonus.h"
# include "../libft/include/libft.h"
// mlx header files
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
// c header files
# include <stdlib.h>
# include <fcntl.h>
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

int		create_map(t_game_data *game_d, int map_fd);
// (create_map_bonus.c)

int		check_path(t_game_data *game_d);
// (check_map_path_bonus.c)

int		init_graphics(t_data *data);
// (init_graphics_bonus.c)

int 	init_mlx(t_data *data);
// (init_mlx_bonus.c)
/* ************************************************************************** */

/* ************************************************************************** */
// display stuff on the monitor screen

void	draw_pixel(t_img *img, int x, int y, unsigned int color);
void	display_tile(t_data *data, int row, int col);
void	display_map(t_data *data);
// (display_map_bonus.c)

void	display_moves(t_data *data);
// (display_moves_bonus.c)
/* ************************************************************************** */

/* ************************************************************************** */
// game logic and event handling

int 	handle_keypress(int keycode, void *data_ptr);
int	    handle_destroy(void *data_ptr);
// (handle_events_bonus.c)

void	end_game(t_data *data, char *msg);
void	move_player(t_data *data, int dx, int dy);
// (game_logic_bonus.c)
/* ************************************************************************** */

/* ************************************************************************** */
// error handling and memory management

void	clean_up(t_data *data);
// (clean_up_bonus.c)

void	free_array(char **array);
void	free_img(t_data *data, t_img *img);
// (clean_up_2_bonus.c)

void	err_msg(char *msg, int show_errno);
// (errors_bonus.c)
/* ************************************************************************** */

#endif
