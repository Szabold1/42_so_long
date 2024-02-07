#include "../include_bonus/so_long_bonus.h"

// check if the map is surrounded by walls and is rectangular
// return 0 if all conditions are met, -1 otherwise
static int	check_walls_and_rectangle(t_game_data *game_d)
{
	int	row;
	int	col;

	row = 0;
	while (game_d->map[row])
	{
		col = 0;
		while (game_d->map[row][col])
		{
			if (row == 0 || col == 0 || col == game_d->cols - 1
				|| row == game_d->rows - 1)
				if (game_d->map[row][col] != WALL)
					return (err_msg("map is not surrounded by walls"), -1);
			col++;
		}
		if (col != game_d->cols)
			return (err_msg("map is not rectangular"), -1);
		row++;
	}
	return (0);
}

// check if the map contains the followings:
// only 1 exit, at least 1 collectible, and only 1 starting position
// return 0 if all conditions are met, -1 otherwise
static int	check_nb_of_characters(t_game_data *game_d)
{
	if (game_d->exit < 1)
		return (err_msg("map does not contain an exit"), -1);
	else if (game_d->exit > 1)
		return (err_msg("map contains more than 1 exit"), -1);
	else if (game_d->collectible < 1)
		return (err_msg("map does not contain any collectibles"), -1);
	else if (game_d->player_start < 1)
		return (err_msg("map does not contain starting position"), -1);
	else if (game_d->player_start > 1)
		return (err_msg("map contains more than 1 starting position"), -1);
	return (0);
}

// check if the map contains valid characters
// return 0 if all conditions are met, -1 otherwise
static int	check_characters(t_game_data *game_d)
{
	int	row;
	int	col;

	if (check_nb_of_characters(game_d) == -1)
		return (-1);
	row = 0;
	while (game_d->map[row])
	{
		col = 0;
		while (game_d->map[row][col])
		{
			if (game_d->map[row][col] != PLAYER
				&& game_d->map[row][col] != EXIT
				&& game_d->map[row][col] != COLLECTIBLE
				&& game_d->map[row][col] != WALL
				&& game_d->map[row][col] != GROUND
				&& game_d->map[row][col] != ENEMY)
				return (err_msg("map contains invalid characters"), -1);
			col++;
		}
		row++;
	}
	return (0);
}

// check if map is valid
// return 0 if it is, -1 otherwise
int	check_map(char *map_filename, t_data *data)
{
	data->map_fd = open(map_filename, O_RDONLY);
	if (data->map_fd == -1)
		return (err_msg("open failed"), -1);
	if (set_game_data(data, data->map_fd) == -1)
		return (err_msg("set_game_data failed"), -1);
	if (check_walls_and_rectangle(data->game_d) == -1
		|| check_characters(data->game_d) == -1
		|| check_path(data) == -1)
		return (-1);
	return (0);
}
