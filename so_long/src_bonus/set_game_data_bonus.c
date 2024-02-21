/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:42 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:14:46 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// set the rest of the game data from the map
// rows, cols, collectible, exit, player_start, player_curr_x, player_curr_y
// if successful, return 0, otherwise return -1
static void	set_game_data_rest(t_game_data *game_d)
{
	int	row;
	int	col;

	row = 0;
	while (game_d->map[row])
	{
		col = 0;
		while (game_d->map[row][col])
		{
			if (game_d->map[row][col] == PLAYER)
			{
				game_d->player_curr_x = col;
				game_d->player_curr_y = row;
				game_d->player_start++;
			}
			else if (game_d->map[row][col] == EXIT)
				game_d->exit++;
			else if (game_d->map[row][col] == COLLECTIBLE)
				game_d->collectible++;
			col++;
		}
		row++;
	}
	game_d->rows = row;
	game_d->cols = col;
}

// set game data from the map file and store it in the game_d struct
// if successful, return 0, otherwise return -1
int	set_game_data(t_data *data, int map_fd)
{
	if (create_map(data->game_d, map_fd) == -1)
		return (err_msg("create_map failed", 0), -1);
	set_game_data_rest(data->game_d);
	return (0);
}
