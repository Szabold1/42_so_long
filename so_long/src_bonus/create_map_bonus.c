/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:17:41 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:18:30 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// set 'map_str' from the map file
// if successful, return 0, otherwise return -1
static int	set_map_str(char **map_str, char *line, int map_fd)
{
	char	*tmp;

	while (line)
	{
		tmp = ft_strjoin(*map_str, line);
		if (tmp == NULL)
			return (free(*map_str), free(line), -1);
		free(*map_str);
		if (ft_strcmp(line, "\n") == 0)
			return (err_msg("there is an empty line in the map", 0),
				free(line), free(tmp), -1);
		*map_str = tmp;
		free(line);
		line = get_next_line(map_fd);
	}
	return (0);
}

// create a string 'map_str' from the map file
// if successful, return the string 'map_str', otherwise return NULL
static char	*create_map_str(int map_fd)
{
	char	*map_str;
	char	*line;

	map_str = ft_strdup("");
	if (map_str == NULL)
		return (NULL);
	line = get_next_line(map_fd);
	if (line == NULL)
		return (err_msg("map is empty", 0), free(map_str), NULL);
	if (set_map_str(&map_str, line, map_fd) == -1)
		return (NULL);
	if (map_str[ft_strlen(map_str) - 1] == '\n')
		return (err_msg("map ends with an empty line", 0),
			free(map_str), NULL);
	return (map_str);
}

// create map_visited array which we will need to check path in the map
// if successful, return 0, otherwise return -1
static int	create_map_visited(t_game_data *game_d, char *map_str)
{
	int	row;
	int	col;

	game_d->map_visited = ft_split(map_str, '\n');
	if (game_d->map_visited == NULL)
		return (-1);
	row = 0;
	while (game_d->map_visited[row])
	{
		col = 0;
		while (game_d->map_visited[row][col])
		{
			game_d->map_visited[row][col] = '0';
			col++;
		}
		row++;
	}
	return (0);
}

// create map from the map file and store it in the game_d struct
// if successful, return 0, otherwise return -1
int	create_map(t_game_data *game_d, int map_fd)
{
	char	*map_str;

	map_str = create_map_str(map_fd);
	if (map_str == NULL)
		return (-1);
	game_d->map = ft_split(map_str, '\n');
	if (game_d->map == NULL)
		return (free(map_str), -1);
	if (create_map_visited(game_d, map_str) == -1)
		return (free(map_str), -1);
	free(map_str);
	return (0);
}
