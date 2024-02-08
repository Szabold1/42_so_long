#include "../include_bonus/so_long_bonus.h"

// free a 2d array of strings
static void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
	}
}

// free the t_img struct and the image it points to
static void	free_img(t_data *data, t_img *img)
{
	if (img)
	{
		if (img->ptr)
		{
			mlx_destroy_image(data->mlx, img->ptr);
			img->ptr = NULL;
		}
		free(img);
	}
}

// free the mlx and all the resources it uses
static void	clean_up_mlx(t_data *data)
{
	if (data->mlx)
	{
		if (data->win)
		{
			mlx_destroy_window(data->mlx, data->win);
			data->win = NULL;
		}
		if (data->img)
		{
			free_img(data, data->img);
			data->img = NULL;
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

// free the textures (t_img structs) and the images they point to
static void	clean_up_textures(t_data *data)
{
	int		i;
	t_img	*textures[5];

	textures[0] = data->player_img;
	textures[1] = data->exit_img;
	textures[2] = data->collectible_img;
	textures[3] = data->wall_img;
	textures[4] = data->ground_img;
	i = 0;
	while (i < 5)
	{
		if (textures[i])
		{
			free_img(data, textures[i]);
			textures[i] = NULL;
		}
		i++;
	}
}

void	clean_up(t_data *data)
{
	if (data)
	{
		if (data->map_fd != -1)
			close(data->map_fd);
		clean_up_mlx(data);
		clean_up_textures(data);
		if (data->game_d)
		{
			if (data->game_d->map)
			{
				free_array(data->game_d->map);
				data->game_d->map = NULL;
			}
			if (data->game_d->map_visited)
			{
				free_array(data->game_d->map_visited);
				data->game_d->map_visited = NULL;
			}
			free(data->game_d);
			data->game_d = NULL;
		}
		free(data);
	}
}