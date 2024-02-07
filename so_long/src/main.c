/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:22:29 by bszabo            #+#    #+#             */
/*   Updated: 2024/01/26 11:22:32 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 1. check if number of arguments matches
// 2. check if file extension is .ber
// return 0 if both conditions are met, -1 otherwise
static int	check_args(int argc, char *argv[])
{
	int	len;

	if (argc != 2)
		return (-1);
	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (err_msg("malloc t_data failed"), EXIT_FAILURE);
	if (check_args(argc, argv) == -1)
		return (clean_up(data), EXIT_FAILURE);
	if (init_data(data) == -1)
		return (clean_up(data), EXIT_FAILURE);
	if (check_map(argv[1], data) == -1)
		return (clean_up(data), EXIT_FAILURE);
	if (init_graphics(data) == -1)
		return (clean_up(data), EXIT_FAILURE);
	display_map(data);
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, (void *)data);
	mlx_hook(data->win, 17, 1L << 17, handle_destroy, (void *)data);
	mlx_loop(data->mlx);
}
