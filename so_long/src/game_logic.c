#include "../include/so_long.h"

// end the game and free all allocated memory
// if msg is not NULL, print it before ending the game
void	end_game(t_data *data, char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	ft_printf("Number of movements: %d\n", data->game_d->moves);
	clean_up(data);
	exit(0);
}

// check if moving to the new position is valid
// return 0 if the new position is valid and -1 otherwise
static bool	check_move(t_game_data *game_d, int x, int y)
{
	if (x < 0 || y < 0 || x >= game_d->cols || y >= game_d->rows)
		return (-1);
	else if (game_d->map[y][x] == WALL)
		return (-1);
	else if (game_d->map[y][x] == GROUND || game_d->map[y][x] == COLLECTIBLE
			|| game_d->map[y][x] == EXIT)
		return (0);
	return (-1);
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
		game_d->collectible--;
		game_d->map[y][x] = PLAYER;
	}
	else if (game_d->map[y][x] == EXIT && game_d->collectible == 0)
		end_game(data, "You won!");
	else if (game_d->map[y][x] == EXIT && game_d->collectible > 0)
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
	if (check_move(data->game_d, new_x, new_y) == 0)
		update_data(data, new_x, new_y);
}
