/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:11:31 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:11:34 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_display_size(t_data *data, int map_width, int map_height)
{
	int	width;
	int	height;

	mlx_get_screen_size(data->mlx, &width, &height);
	if (map_width > width)
		return (err_msg("map is too big horizontally", 0), -1);
	if (map_height > height)
		return (err_msg("map is too big vertically", 0), -1);
	return (0);
}

// initialize mlx, window, image, and data about the image
// return 0 if successful, -1 otherwise
static int	init_mlx(t_data *data)
{
	int	width;
	int	height;

	width = data->game_d->cols * TILE_SIZE;
	height = data->game_d->rows * TILE_SIZE;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (err_msg("mlx_init() failed", 1), -1);
	if (check_display_size(data, width, height) == -1)
		return (-1);
	data->win = mlx_new_window(data->mlx, width, height, "so_long");
	if (!data->win)
		return (err_msg("mlx_new_window() failed", 1), -1);
	data->img->ptr = mlx_new_image(data->mlx, width, height);
	if (!data->img->ptr)
		return (err_msg("mlx_new_image() failed", 1), -1);
	data->img->addr = mlx_get_data_addr(data->img->ptr,
			&data->img->bits_per_pixel, &data->img->line_len,
			&data->img->endian);
	if (!data->img->addr)
		return (err_msg("mlx_get_data_addr() failed", 1), -1);
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
		|| load_texture(data, data->ground_img, GROUND_PATH) == -1)
		return (-1);
	return (0);
}

// initialize mlx and load textures
// return 0 if successful, -1 otherwise
int	init_graphics(t_data *data)
{
	if (init_mlx(data) == -1)
		return (err_msg("init_mlx failed", 0), -1);
	if (load_textures(data) == -1)
		return (err_msg("load_textures failed", 0), -1);
	return (0);
}
