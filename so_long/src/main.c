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

	if (!check_args(argc, argv))
		exit_free_game_data(game_d, "Error\nInvalid arguments\n");
	game_d = set_game_data(argv[1]);
	data = set_graphics_data(game_d);
}
