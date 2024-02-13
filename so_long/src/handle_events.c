/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:22:07 by bszabo            #+#    #+#             */
/*   Updated: 2024/01/26 11:22:19 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// refresh the screen by redrawing player cell and cells next to it
static void	refresh_screen(t_data *data)
{
	int	player_curr_x;
	int	player_curr_y;

	player_curr_x = data->game_d->player_curr_x;
	player_curr_y = data->game_d->player_curr_y;
	if (player_curr_x > 0 && player_curr_y > 0
		&& player_curr_x < data->game_d->cols - 1
		&& player_curr_y < data->game_d->rows - 1)
	{
		display_tile(data, player_curr_y, player_curr_x);
		display_tile(data, player_curr_y - 1, player_curr_x);
		display_tile(data, player_curr_y + 1, player_curr_x);
		display_tile(data, player_curr_y, player_curr_x - 1);
		display_tile(data, player_curr_y, player_curr_x + 1);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->ptr, 0, 0);
}

// handle the case when a key is pressed (KeyPress event)
// if the key pressed is ESC, exit the program
// if the key pressed is an arrow key, move the player
// refresh the screen after every event
int	handle_keypress(int keycode, void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
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
	return (0);
}

// handle the case when the window is closed (DestroyNotify event)
int	handle_destroy(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	end_game(data, NULL);
	return (-1);
}
