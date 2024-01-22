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

int	main(int argc, char *argv[])
{
	t_game_data	*game_d;
	t_data		*data;

	game_d = NULL;
	data = NULL;
	if (!check_args(argc, argv))
		exit_error("Error\nInvalid arguments\n");
	game_d = set_game_data(argv[1], data);
	data = set_graphics_data(game_d);
	draw_map(game_d, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
				handle_destroy, data);
	mlx_loop(data->mlx_ptr);
	exit_free(data, game_d, "");
}
