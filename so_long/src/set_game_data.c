# include "../include/so_long.h"

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
static bool    fill_game_data(t_game_data *game_d, int file)
{
    game_d->map = NULL;
    game_d->rows = 0;
    game_d->cols = 0;
    game_d->collect = 0;
    game_d->exit = 0;
    game_d->start = 0;
	game_d->player_row = -1;
	game_d->player_col = -1;
	game_d->moves = 0;
    if (!create_map(game_d, file))
		return (false);
	return (true);
}

// fill t_game_data structure and check if map is valid
t_game_data	*set_game_data(char *filename)
{
	int			i;
	int			j;
	t_game_data	*game_d;
	int			file;

	i = 0;
	j = 0;
	game_d = (t_game_data *)malloc(sizeof(t_game_data));
	if (game_d == NULL)
		exit_error("Error\nmalloc returned NULL\n");
	file = open(filename, O_RDONLY);
	if (file == -1)
		exit_free_game_data(game_d, "Error\nFile opening failed\n");
	if (!fill_game_data(game_d, file)
		|| !check_rect_walls(game_d->map, i, j)
		|| !check_elements_path(game_d, i, j))
	{
		if (close(file) == -1)
			exit_free_game_data(game_d, "Error\nFile closing failed\n");
		exit_free_game_data(game_d, "Error\nInvalid map\n");
	}
	if (close(file) == -1)
		exit_free_game_data(game_d, "Error\nFile closing failed\n");
	return (game_d);
}
