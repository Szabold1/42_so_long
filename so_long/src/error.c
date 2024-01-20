#include "../include/so_long.h"

// print error message with perror() and exit
void	exit_error(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

// free t_game_data structure and exit with error message
void    exit_free_game_data(t_game_data *game_d, char *err_msg)
{
    int	i;

    i = 0;
    while (game_d->map && game_d->map[i])
    {
        free(game_d->map[i]);
        i++;
    }
    free(game_d->map);
    free(game_d);
    exit_error(err_msg);
}

// free t_data and t_game_data structures and exit with error message
void	exit_free_data(t_data *data, t_game_data *game_d, char *err_msg)
{
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	free(data);
	exit_free_game_data(game_d, err_msg);
}
