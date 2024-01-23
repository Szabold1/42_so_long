# include "../include/so_long.h"

// check if moving to the new position is valid
// return true if the new position is valid and false otherwise
static bool	is_valid_move(t_data *data, int x, int y)
{
	t_game_data	*game_d;

	game_d = data->game_d;
	if (x < 0 || y < 0 || x >= game_d->cols || y >= game_d->rows)
		return (false);
	else if (game_d->map[y][x] == WALL)
		return (false);
	else if (game_d->map[y][x] == GROUND || game_d->map[y][x] == COLLECTIBLE
			|| game_d->map[y][x] == EXIT)
		return (true);
}

// update the necessary data when the player moves to a new position
// x and y are the new coordinates of the player
// end the game if the player reaches the exit
static void	update_data(t_data *data, int x, int y)
{
	t_game_data	*game_d;

	game_d = data->game_d;
	game_d->map[game_d->player_curr_y][game_d->player_curr_x] = GROUND;
	game_d->player_curr_x = x;
	game_d->player_curr_y = y;
	game_d->moves++;
	if (game_d->map[y][x] == GROUND)
		game_d->map[y][x] = PLAYER;
	else if (game_d->map[y][x] == COLLECTIBLE)
	{
		game_d->collect--;
		game_d->map[y][x] = PLAYER;
	}
	else if (game_d->map[y][x] == EXIT && game_d->collect == 0)
		end_game(data, "You won!");
	else if (game_d->map[y][x] == EXIT && game_d->collect > 0)
		end_game(data, "You lost! You didn't collect all collectibles!");
}

// update the necessary data when the player moves to a new position
// if the new position is invalid, do nothing
// x and y are the relative coordinates of the new position
void	move_player(t_data *data, int x, int y)
{
    int	new_x;
	int	new_y;

	new_x = data->game_d->player_curr_x + x;
	new_y = data->game_d->player_curr_y + y;
	if (is_valid_move(data->game_d, new_x, new_y))
		update_data(data, new_x, new_y);
}