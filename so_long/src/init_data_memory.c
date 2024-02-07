#include "../include/so_long.h"

// allocate memory for all textures (t_img)
// return 0 if successful, -1 otherwise
static int	init_memory_textures(t_data *data)
{
	data->player_img = (t_img *)malloc(sizeof(t_img));
	if (!data->player_img)
		return (err_msg("malloc player_img failed"), -1);
	data->exit_img = (t_img *)malloc(sizeof(t_img));
	if (!data->exit_img)
		return (err_msg("malloc exit_img failed"), -1);
	data->collectible_img = (t_img *)malloc(sizeof(t_img));
	if (!data->collectible_img)
		return (err_msg("malloc collectible_img failed"), -1);
	data->wall_img = (t_img *)malloc(sizeof(t_img));
	if (!data->wall_img)
		return (err_msg("malloc wall_img failed"), -1);
	data->ground_img = (t_img *)malloc(sizeof(t_img));
	if (!data->ground_img)
		return (err_msg("malloc ground_img failed"), -1);
	return (0);
}

// allocate memory for all data structures
// return 0 if successful, -1 otherwise
int	init_memory(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	if (!data->img)
		return (err_msg("malloc t_img failed"), -1);
	if (init_memory_textures(data) == -1)
		return (-1);
	data->game_d = (t_game_data *)malloc(sizeof(t_game_data));
	if (!data->game_d)
		return (err_msg("malloc t_game_data failed"), -1);
	return (0);
}
