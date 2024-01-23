# include "../include/so_long.h"

// refresh the screen by redrawing player cell and cells around it
// and put the image to the window
static void	refresh_screen(t_data *data)
{
	int	row;
	int	col;

	row = data->game_d->player_curr_y - 1;
	col = data->game_d->player_curr_x - 1;
	while (row <= data->game_d->player_curr_y + 1)
	{
		while (col <= data->game_d->player_curr_x + 1)
			handle_draw_cell(data, row, col++);
		row++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_ptr->ptr, 0, 0);
}

// handle KeyPress events
// if the key pressed is ESC, exit the program
// if the key pressed is an arrow key, move the player
// refresh the screen after every event
void	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		end_game(data, NULL);
	else if (keycode == KEY_UP_ARROW)
		move_player(data, 0, -1);
	else if (keycode == KEY_DOWN_ARROW)
		move_player(data, 0, 1);
	else if (keycode == KEY_LEFT_ARROW)
		move_player(data, -1, 0);
	else if (keycode == KEY_RIGHT_ARROW)
		move_player(data, 1, 0);
	refresh_screen(data);
}

// handle DestroyNotify events
void	handle_destroy(t_data *data)
{
	end_game(data, NULL);
}
