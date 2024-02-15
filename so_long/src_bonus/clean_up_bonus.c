/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:12:51 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:12:55 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

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
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

// free the textures (t_img structs) and the images they point to
static void	clean_up_textures(t_data *data)
{
	int		i;
	t_img	*textures[6];

	textures[0] = data->player_img;
	textures[1] = data->exit_img;
	textures[2] = data->collectible_img;
	textures[3] = data->wall_img;
	textures[4] = data->ground_img;
	textures[5] = data->enemy_img;
	i = 0;
	while (i < 6)
	{
		if (textures[i])
		{
			free_img(data, textures[i]);
			textures[i] = NULL;
		}
		i++;
	}
}

static void	clean_up_game_data(t_data *data)
{
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
}

void	clean_up(t_data *data)
{
	if (data)
	{
		if (data->map_fd != -1)
			close(data->map_fd);
		if (data->img)
		{
			free_img(data, data->img);
			data->img = NULL;
		}
		clean_up_textures(data);
		clean_up_game_data(data);
		clean_up_mlx(data);
		free(data);
	}
}
