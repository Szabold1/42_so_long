#include "../include/so_long.h"

// print error message with perror() and exit
void	exit_error(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

// free t_game_data structure and exit if 'err_msg' is not an empty string
static void	exit_free_game_data(t_game_data *game_d, char *err_msg)
{
    int	i;

    i = 0;
	if (game_d)
	{
		while (game_d->map && game_d->map[i])
		{
			free(game_d->map[i]);
			i++;
		}
		free(game_d->map);
		free(game_d);
	}
	if (err_msg)
    	exit_error(err_msg);
}

// free t_img structure
static void	exit_free_texture(t_img *texture, void *mlx_ptr, char *err_msg)
{
    if (texture)
    {
        if (texture->ptr)
            mlx_destroy_image(mlx_ptr, texture->ptr);
        free(texture);
    }
	if (err_msg)
		exit_error(err_msg);
		
}

// free t_data structure and exit if 'err_msg' is not an empty string
static void	exit_free_data(t_data *data, char *err_msg)
{
	if (data)
	{
		if (data->mlx_ptr)
		{
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit_free_texture(data->img_ptr, data->mlx_ptr, "");
		exit_free_texture(data->player_ptr, data->mlx_ptr, "");
		exit_free_texture(data->exit_ptr, data->mlx_ptr, "");
		exit_free_texture(data->collect_ptr, data->mlx_ptr, "");
		exit_free_texture(data->wall_ptr, data->mlx_ptr, "");
		exit_free_texture(data->ground_ptr, data->mlx_ptr, "");
		free(data);
	}
	if (err_msg)
		exit_error(err_msg);
}

// free t_game_data and t_data structures,
// and exit if 'err_msg' is not an empty string
void	exit_free(t_data *data, t_game_data *game_d, char *err_msg)
{
	exit_free_data(data, "");
	exit_free_game_data(game_d, "");
	if (err_msg)
		exit_error(err_msg);
}