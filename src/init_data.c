/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:10:59 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:11:02 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// initialize 'img' with default values
static void	init_img(t_img *img)
{
	img->ptr = NULL;
	img->addr = NULL;
	img->width = 0;
	img->height = 0;
	img->bits_per_pixel = 0;
	img->line_len = 0;
	img->endian = 0;
}

// initialize all textures with default values
static void	init_textures(t_data *data)
{
	init_img(data->player_img);
	init_img(data->exit_img);
	init_img(data->collectible_img);
	init_img(data->wall_img);
	init_img(data->ground_img);
}

// initialize t_game_data struct with default values
static void	init_game_data(t_game_data *game_d)
{
	game_d->map = NULL;
	game_d->map_visited = NULL;
	game_d->rows = 0;
	game_d->cols = 0;
	game_d->collectible = 0;
	game_d->exit = 0;
	game_d->player_start = 0;
	game_d->player_curr_x = -1;
	game_d->player_curr_y = -1;
	game_d->moves = 0;
}

// initialize all data structures with default values
int	init_data(t_data *data)
{
	data->map_fd = -1;
	data->mlx = NULL;
	data->win = NULL;
	if (init_memory(data) == -1)
		return (-1);
	ft_printf_fd(2, "init_memory passed\n");
	init_img(data->img);
	ft_printf_fd(2, "init_img passed\n");
	init_textures(data);
	ft_printf_fd(2, "init_textures passed\n");
	init_game_data(data->game_d);
	return (0);
}
