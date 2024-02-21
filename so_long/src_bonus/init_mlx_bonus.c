/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:24:20 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:24:29 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
int	init_mlx(t_data *data)
{
	int	width;
	int	height;

	width = data->game_d->cols * TILE_SIZE;
	height = data->game_d->rows * TILE_SIZE + MOVES_TEXT_HEIGHT;
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
