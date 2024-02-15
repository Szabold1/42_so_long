#include "../include_bonus/so_long_bonus.h"

// fill the img with a single color
static void	fill_img_with_color(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			draw_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

// display the number of moves on the screen
void	display_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->game_d->moves);
	if (!moves)
		end_game(data, "ft_itoa failed in display_moves");
	fill_img_with_color(data->moves_img, 0x00FFC100);
	mlx_put_image_to_window(data->mlx, data->win, data->moves_img->ptr, 0, 0);
	mlx_string_put(data->mlx, data->win, 10, MOVES_TEXT_HEIGHT / 1.35,
		0x00000000, "Moves:");
	mlx_string_put(data->mlx, data->win, 60, MOVES_TEXT_HEIGHT / 1.35,
		0x00000000, moves);
	free(moves);
}
