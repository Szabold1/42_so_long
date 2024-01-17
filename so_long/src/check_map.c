# include "../include/so_long.h"

// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.

// check if map is rectangular and closed/surrounded by walls
// also set the number of rows and columns in t_map_data
// return true if all conditions are met, false otherwise
static bool	check_rect_walls(t_map_data *map_data, int i, int j)
{
	int	len;

	if (map_data->map[0] == NULL)
		return (false);
	len = ft_strlen(map_data->map[0]);
	while (map_data->map[i])
	{
		while (map_data->map[i][j])
		{
			if ((i == 0 || j == 0 || j == len - 1 || !map_data->map[i + 1]
				|| map_data->map[i + 1][0] == '\0')
				&& (map_data->map[i][j] != '1'))
				return (false);
			j++;
		}
		if (j != len)
			return (false);
		i++;
	}
	map_data->rows = i;
	map_data->cols = j;
	return (true);
}

// check if there's a valid path from 'start' to 'exit' (depth first search)
// return true if there's a valid path, false otherwise
static bool	dfs_find_exit(t_map_data *map_data, int row, int col,
					int visited[map_data->rows][map_data->cols])
{
	if (row < 0 || col < 0 || row >= map_data->rows || col >= map_data->cols
		|| visited[row][col] == 1 || map_data->map[row][col] == '1')
		return (false);
	visited[row][col] = 1;
	if (map_data->map[row][col] == 'E')
		return (true);
	return (dfs_find_exit(map_data, row - 1, col, visited)
		|| dfs_find_exit(map_data, row + 1, col, visited)
		|| dfs_find_exit(map_data, row, col - 1, visited)
		|| dfs_find_exit(map_data, row, col + 1, visited));
}

// check if map contains the followings:
// 1 exit, at least 1 collectible, 1 starting position, and a valid path
// return true if all conditions are met, false otherwise
static bool	check_elements_path(t_map_data *map_data, int i, int j)
{
	int	visited[map_data->rows][map_data->cols];

	ft_memset(visited, 0, sizeof(visited));
	while (map_data->map[i])
	{
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == 'C')
				map_data->collect++;
			else if (map_data->map[i][j] == 'E')
				map_data->exit++;
			else if (map_data->map[i][j] == 'P'
					&& dfs_find_exit(map_data, i, j, visited))
				map_data->start++;
			else if (map_data->map[i][j] != '0' && map_data->map[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	if (map_data->collect < 1 || map_data->exit != 1 || map_data->start != 1)
		return (false);
	return (true);
}

// 1. initialize map_data structure with default values
// and set map_data->map to the map from the file (array of strings)
// 2. check if map is valid
void	check_map(char *filename)
{
	t_map_data	*map_data;
	int			file;
	int			i;
	int			j;

	i = 0;
	j = 0;
	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (map_data == NULL)
		exit_error("Error\nmalloc returned NULL\n");
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		free_map_data(map_data);
		exit_error("Error\nFile opening failed\n");
	}
	if (!init_map_data(map_data, file)
		|| !check_rect_walls(map_data->map, i, j)
		|| !check_elements_path(map_data, i, j))
	{
		free_map_data(map_data);
		if (close(file) == -1)
			exit_error("Error\nFile closing failed\n");
		exit_error("Error\nInvalid map\n");
	}
}