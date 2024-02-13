/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:54:08 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:54:12 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// free a 2d array of strings
void	free_array(char **array)
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
void	free_img(t_data *data, t_img *img)
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
