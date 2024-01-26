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

// 1. create a string from the map
// 2. split the string by new lines into an array of strings
// and store it in game_d->map
static bool	create_map(t_game_data *game_d, int file)
{
	char	*map_str;
	char	*line;

	map_str = NULL;
	line = get_next_line(file);
	if (line == NULL)
		return (false);
	while (line)
	{
		map_str = ft_strjoin(map_str, line);
		free(line);
		line = get_next_line(file);
	}
	game_d->map = ft_split(map_str, '\n');
	if (game_d->map == NULL)
	{
		free(map_str);
		return (false);
	}
	free(map_str);
	return (true);
}

// initialize t_game_data structure with default values
// and set game_d->map to the map from the file
static bool	fill_game_data(t_game_data *game_d, int file)
{
	game_d->map = NULL;
	game_d->rows = 0;
	game_d->cols = 0;
	game_d->collect = 0;
	game_d->exit = 0;
	game_d->start = 0;
	game_d->player_curr_x = -1;
	game_d->player_curr_y = -1;
	game_d->moves = 0;
	if (!create_map(game_d, file))
		return (false);
	return (true);
}

// fill t_game_data structure and check if map is valid
// return t_game_data structure if map is valid, exit otherwise
t_game_data	*set_game_data(char *filename, t_data *data, t_game_data *game_d)
{
	int	i;
	int	j;
	int	file;

	i = 0;
	j = 0;
	file = open(filename, O_RDONLY);
	if (file == -1)
		exit_free(data, "Error\nFile opening failed\n");
	if (!fill_game_data(game_d, file)
		|| !check_rect_walls(game_d, i, j)
		|| !check_elements_path(game_d, i, j))
	{
		if (close(file) == -1)
			exit_free(data, "Error\nFile closing failed\n");
		exit_free(data, "Error\nInvalid map\n");
	}
	if (close(file) == -1)
		exit_free(data, "Error\nFile closing failed\n");
	return (game_d);
}
