/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:20 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:14:23 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

// load img for displaying moves
// return 0 if successful, -1 otherwise
static int	load_moves_img(t_data *data)
{
	data->moves_img->ptr = mlx_new_image(data->mlx,
			data->game_d->cols * TILE_SIZE, MOVES_TEXT_HEIGHT);
	if (!data->moves_img->ptr)
		return (err_msg("mlx_new_image() failed", 1), -1);
	data->moves_img->addr = mlx_get_data_addr(data->moves_img->ptr,
			&data->moves_img->bits_per_pixel, &data->moves_img->line_len,
			&data->moves_img->endian);
	if (!data->moves_img->addr)
		return (err_msg("mlx_get_data_addr() failed", 1), -1);
	data->moves_img->width = data->game_d->cols * TILE_SIZE;
	data->moves_img->height = MOVES_TEXT_HEIGHT;
	return (0);
}

// make img from xpm files and get data about img
// return 0 if successful, -1 otherwise
static int	load_texture(t_data *data, t_img *img, char *file_path)
{
	img->ptr = mlx_xpm_file_to_image(data->mlx, file_path,
			&img->width, &img->height);
	if (!img->ptr)
		return (err_msg("mlx_xpm_file_to_image() failed", 1), -1);
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
			&img->line_len, &img->endian);
	if (!img->addr)
		return (err_msg("mlx_get_data_addr() failed", 1), -1);
	return (0);
}

// load all textures into their respective t_img structs
// return 0 if successful, -1 otherwise
static int	load_textures(t_data *data)
{
	if (load_texture(data, data->player_img, PLAYER_PATH) == -1
		|| load_texture(data, data->exit_img, EXIT_PATH) == -1
		|| load_texture(data, data->collectible_img, COLLECTIBLE_PATH) == -1
		|| load_texture(data, data->wall_img, WALL_PATH) == -1
		|| load_texture(data, data->ground_img, GROUND_PATH) == -1
		|| load_texture(data, data->enemy_img, ENEMY_PATH) == -1)
		return (-1);
	return (0);
}

// initialize mlx and load textures
// return 0 if successful, -1 otherwise
int	init_graphics(t_data *data)
{
	if (init_mlx(data) == -1)
		return (err_msg("init_mlx failed", 0), -1);
	if (load_moves_img(data) == -1)
		return (err_msg("load_moves_img failed", 0), -1);
	if (load_textures(data) == -1)
		return (err_msg("load_textures failed", 0), -1);
	return (0);
}
