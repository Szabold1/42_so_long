# include "../include/so_long.h"

// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.

// count the number of rows in the map (2D array) and return it
static int	get_nb_rows(char **map)
{
	int	row;

	row = 0;
	while (map[row])
		row++;
	return (row);
}

// check if map is rectangular and closed/surrounded by walls
// also set the number of rows and columns in t_game_data
// return true if all conditions are met, false otherwise
bool	check_rect_walls(t_game_data *game_d, int row, int col)
{
	int	len;
	int	nb_rows;

	if (game_d->map[0] == NULL)
		return (false);
	len = ft_strlen(game_d->map[0]);
	nb_rows = get_nb_rows(game_d->map);
	while (game_d->map[row])
	{
		while (game_d->map[row][col])
		{
			if ((row == 0 || col == 0 || col == len - 1 || row == nb_rows - 1)
				&& (game_d->map[row][col] != WALL))
				return (false);
			col++;
		}
		if (col != len)
			return (false);
		row++;
	}
	game_d->rows = row;
	game_d->cols = col;
	return (true);
}

// (depth-first search)
// check if there's a valid path from 'start' to 'exit' and to all collectibles
// return true if there's a valid path, false otherwise
static bool	dfs_check_path(t_game_data *game_d, int row, int col,
					int visited[game_d->rows][game_d->cols])
{
	static bool	exit;
	static int	collect;

	exit = false;
	collect = game_d->collect;
	if (row < 0 || col < 0 || row >= game_d->rows || col >= game_d->cols
		|| visited[row][col] == 1 || game_d->map[row][col] == WALL)
		return (false);
	visited[row][col] = 1;
	if (game_d->map[row][col] == EXIT)
		exit = true;
	else if (game_d->map[row][col] == COLLECTIBLE)
		collect--;
	if (exit && (collect == 0))
		return (true);
	return (dfs_check_path(game_d, row - 1, col, visited)
		|| dfs_check_path(game_d, row + 1, col, visited)
		|| dfs_check_path(game_d, row, col - 1, visited)
		|| dfs_check_path(game_d, row, col + 1, visited));
}

// set the starting position of the player
// return true if the starting position is set, false otherwise
static bool	set_start_pos(t_game_data *game_d, int row, int col)
{
	if (game_d->player_curr_x != -1 || game_d->player_curr_y != -1)
		return (false);
	game_d->player_curr_y = row;
	game_d->player_curr_x = col;
	game_d->map[row][col] = PLAYER;
	return (true);
}

// check if map contains the followings:
// 1 exit, at least 1 collectible, 1 starting position, and a valid path
// also set the starting position of the player,
// and the number of collect, exit, and start in t_game_data
// return true if all conditions are met, false otherwise
bool	check_elements_path(t_game_data *game_d, int i, int j)
{
	int	visited[game_d->rows][game_d->cols];

	ft_memset(visited, 0, sizeof(visited));
	while (game_d->map[i])
	{
		while (game_d->map[i][j])
		{
			if (game_d->map[i][j] == COLLECTIBLE)
				game_d->collect++;
			else if (game_d->map[i][j] == EXIT)
				game_d->exit++;
			else if (game_d->map[i][j] == 'P' && set_start_pos(game_d, i, j))
				game_d->start++;
			else if (game_d->map[i][j] != GROUND && game_d->map[i][j] != WALL)
				return (false);
			j++;
		}
		i++;
	}
	if (!dfs_check_path(game_d, game_d->player_curr_y, game_d->player_curr_x,
			visited))
		return (false);
	if (game_d->collect < 1 || game_d->exit != 1 || game_d->start != 1)
		return (false);
	return (true);
}
