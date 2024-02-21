/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:13:03 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:13:04 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// get the color of a pixel from the 'img' at (x, y)
// return the color as an unsigned int
static unsigned int	get_pixel_color(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

// draw a pixel on the 'img' at (x, y) with 'color'
void	draw_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

// draw a rectangle on the 'img_dest' with top left corner at (row, col),
// using the 'img_src' as the texture
// size of the rectangle is TILE_SIZE x TILE_SIZE
static void	draw_tile(t_img *img_dest, t_img *img_src, int row, int col)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			color = get_pixel_color(img_src, x, y);
			draw_pixel(img_dest, col * TILE_SIZE + x,
				row * TILE_SIZE + y, color);
			x++;
		}
		y++;
	}
}

// draw a tile to the image at (row, col) based on the texture
void	display_tile(t_data *data, int row, int col)
{
	char	**map;

	map = data->game_d->map;
	if (map[row][col] == PLAYER)
		draw_tile(data->img, data->player_img, row, col);
	else if (map[row][col] == EXIT)
		draw_tile(data->img, data->exit_img, row, col);
	else if (map[row][col] == COLLECTIBLE)
		draw_tile(data->img, data->collectible_img, row, col);
	else if (map[row][col] == WALL)
		draw_tile(data->img, data->wall_img, row, col);
	else if (map[row][col] == GROUND)
		draw_tile(data->img, data->ground_img, row, col);
	else if (map[row][col] == ENEMY)
		draw_tile(data->img, data->enemy_img, row, col);
}

// display the map on the window
void	display_map(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->game_d->rows)
	{
		col = 0;
		while (col < data->game_d->cols)
		{
			display_tile(data, row, col);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->ptr, 0,
		MOVES_TEXT_HEIGHT);
}
