# include "../include/so_long.h"

// 1. check if number of arguments matches
// 2. check if file extension is .ber
// return true if both conditions are met, false otherwise
static bool	check_args(int argc, char *argv[])
{
	int	len;

	if (argc != 2)
		return (false);
	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		return (false);
	return (true);
}

// 1. allocate memory for data structures
// 2. check the arguments
// 3. check if map is valid and get data about the map
// 4. initialize mlx, window, image, data about the image, and textures
// 4. draw the map to the image
// 5. set up event handlers and start the game loop
int	main(int argc, char *argv[])
{
	t_game_data	*game_d;
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		exit_error("Error\nmalloc returned NULL\n");
	game_d = (t_game_data *)malloc(sizeof(t_game_data));
	if (game_d == NULL)
		exit_free(data, "Error\nmalloc returned NULL\n");
	if (!check_args(argc, argv))
		exit_free(data, "Error\nInvalid arguments\n");
	game_d = set_game_data(argv[1], data, game_d);
	data = set_graphics_data(data);
	draw_map(game_d, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
				handle_destroy, data);
	mlx_loop(data->mlx_ptr);
}
