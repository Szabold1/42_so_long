/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:22:59 by bszabo            #+#    #+#             */
/*   Updated: 2024/01/26 11:23:08 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// create a string 'map_str' from the map,
// and split it by new lines into an array of strings 'game_d->map'
// if successful, return 0, otherwise return -1
static int	create_map(t_game_data *game_d, int map_fd)
{
	char	*map_str;
	char	*line;

	map_str = NULL;
	line = get_next_line(map_fd);
	if (line == NULL)
		return (-1);
	while (line)
	{
		map_str = ft_strjoin(map_str, line);
		if (map_str == NULL)
			return (free(line), -1);
		free(line);
		line = get_next_line(map_fd);
	}
	free(line);
	game_d->map = ft_split(map_str, '\n');
	if (game_d->map == NULL)
		return (free(map_str), -1);
	free(map_str);
	return (0);
}

// set the rest of the game data from the map
// rows, cols, collectible, exit, player_start, player_curr_x, player_curr_y
// if successful, return 0, otherwise return -1
static int	set_game_data_rest(t_game_data *game_d)
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
		return (-1);
	if (set_game_data_rest(data->game_d) == -1)
		return (-1);
	return (0);
}
