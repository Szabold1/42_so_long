/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:12:39 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:12:43 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

// (depth-first search)
// return 0 if there's a valid path, -1 otherwise
static int	dfs_check_path(t_game_data *game_d, int y, int x, int *collect)
{
	if (game_d->map[y][x] == WALL || game_d->map_visited[y][x] == '1' || game_d->map[y][x] == ENEMY)
		return (-1);
	if (game_d->map[y][x] == EXIT)
		game_d->exit_reached = true;
	if (game_d->map[y][x] == COLLECTIBLE)
		(*collect)--;
	game_d->map_visited[y][x] = '1';
	if (game_d->exit_reached && *collect == 0)
		return (0);
	if (dfs_check_path(game_d, y - 1, x, collect) == 0
		|| dfs_check_path(game_d, y + 1, x, collect) == 0
		|| dfs_check_path(game_d, y, x - 1, collect) == 0
		|| dfs_check_path(game_d, y, x + 1, collect) == 0)
		return (0);
	return (-1);
}

// check if there's a valid path from 'start' to 'exit' and to all collectibles
// return 0 if there's a valid path, -1 otherwise
int	check_path(t_game_data *game_d)
{
	int		collect;

	collect = game_d->collectible;
	if (dfs_check_path(game_d, game_d->player_curr_y, game_d->player_curr_x, &collect) == -1)
		return (err_msg("no valid path in the map", 0), -1);
	return (0);
}
