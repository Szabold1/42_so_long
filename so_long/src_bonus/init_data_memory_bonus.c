/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_memory_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:01 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:14:06 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// allocate memory for all textures (t_img)
// return 0 if successful, -1 otherwise
static int	init_memory_textures(t_data *data)
{
	int		i;
	t_img	**textures[6];

	textures[0] = &(data->player_img);
	textures[1] = &(data->exit_img);
	textures[2] = &(data->collectible_img);
	textures[3] = &(data->wall_img);
	textures[4] = &(data->ground_img);
	textures[5] = &(data->enemy_img);
	i = 0;
	while (i < 6)
	{
		*textures[i] = (t_img *)malloc(sizeof(t_img));
		if (!(*textures[i]))
			return (err_msg("malloc textures failed", 1), -1);
		i++;
	}
	return (0);
}

// allocate memory for all data structures
// return 0 if successful, -1 otherwise
int	init_memory(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	if (!data->img)
		return (err_msg("malloc img failed", 1), -1);
	data->moves_img = (t_img *)malloc(sizeof(t_img));
	if (!data->moves_img)
		return (err_msg("malloc moves_img failed", 1), -1);
	if (init_memory_textures(data) == -1)
		return (-1);
	data->game_d = (t_game_data *)malloc(sizeof(t_game_data));
	if (!data->game_d)
		return (err_msg("malloc t_game_data failed", 1), -1);
	return (0);
}
