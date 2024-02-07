#include "../include_bonus/so_long_bonus.h"

// (depth-first search)
// return 0 if there's a valid path, -1 otherwise
static int	dfs_check_path(t_game_data *game_d, int row, int col,
					int **visited)
{
	static bool	exit;
	static int	collect;

	exit = false;
	collect = game_d->collectible;
	if (row < 0 || col < 0 || row >= game_d->rows || col >= game_d->cols
		|| visited[row][col] == 1 || game_d->map[row][col] == WALL
		|| game_d->map[row][col] == ENEMY)
		return (-1);
	visited[row][col] = 1;
	if (game_d->map[row][col] == EXIT)
		exit = true;
	else if (game_d->map[row][col] == COLLECTIBLE)
		collect--;
	if (exit && (collect == 0))
		return (0);
	return (dfs_check_path(game_d, row - 1, col, visited)
		|| dfs_check_path(game_d, row + 1, col, visited)
		|| dfs_check_path(game_d, row, col - 1, visited)
		|| dfs_check_path(game_d, row, col + 1, visited));
}

// check if there's a valid path from 'start' to 'exit' and to all collectibles
// return 0 if there's a valid path, -1 otherwise
int	check_path(t_game_data *game_d)
{
	if (dfs_check_path(game_d, game_d->player_curr_y,
			game_d->player_curr_x, game_d->map_visited) == -1)
		return (err_msg("no valid path in the map"), -1);
	return (0);
}
