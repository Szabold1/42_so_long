# include "../include/so_long.h"

// get the color of a pixel from the 'img' at (x, y)
// return the color as an unsigned int
static unsigned int	get_pixel_color(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

// draw a pixel on the 'img' at (x, y) with 'color'
static void	draw_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

// draw a rectangle on the 'img_dest' with top left corner at (row, col),
// using the 'img_src' as the texture
// size of the rectangle is CELL_SIZE x CELL_SIZE
static void	draw_cell(t_img *img_dest, t_img *img_src, int row, int col)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < CELL_SIZE)
	{
		x = 0;
		while (x < CELL_SIZE)
		{
			color = get_pixel_color(img_src, x, y);
			draw_pixel(img_dest,
				col * CELL_SIZE + x, row * CELL_SIZE + y, color);
			x++;
		}
		y++;
	}
}

// draw the map to the image (data->img_ptr) using the textures from t_data
void	draw_map(t_game_data *game_d, t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < game_d->rows)
	{
		col = 0;
		while (col < game_d->cols)
		{
			if (game_d->map[row][col] == '1')
				draw_cell(data->img_ptr, data->wall_ptr, row, col);
			else if (game_d->map[row][col] == '0')
				draw_cell(data->img_ptr, data->ground_ptr, row, col);
			else if (game_d->map[row][col] == 'C')
				draw_cell(data->img_ptr, data->collect_ptr, row, col);
			else if (game_d->map[row][col] == 'E')
				draw_cell(data->img_ptr, data->exit_ptr, row, col);
			else if (game_d->map[row][col] == 'P')
				draw_cell(data->img_ptr, data->player_ptr, row, col);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
