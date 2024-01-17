# include "../include/so_long.h"

// 1. create a string from the map
// 2. split the string by new lines into an array of strings
// and store it in map_data->map
static bool	create_map(t_map_data *map_data, int file)
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
	map_data->map = ft_split(map_str, '\n');
	if (map_data->map == NULL)
		return (false);
	free(map_str);
	return (true);
}

// initialize t_map_data structure with default values
// and set map_data->map to the map from the file
bool    init_map_data(t_map_data *map_data, int file)
{
    map_data->map = NULL;
    map_data->rows = 0;
    map_data->cols = 0;
    map_data->collect = 0;
    map_data->exit = 0;
    map_data->start = 0;
    if (!create_map(map_data, file))
		return (false);
	return (true);
}