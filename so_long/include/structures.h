/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:06:54 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:06:58 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// structure for holding data related to the game
typedef struct s_game_data
{
	char	**map;
	char	**map_visited;
	int		rows;
	int		cols;
	int		collectible;
	int		exit;
	int		player_start;
	int		player_curr_x;
	int		player_curr_y;
	int		moves;
}	t_game_data;

// structure for holding data related to an image
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

// structure for holding all data related to so_long
typedef struct s_data
{
	int			map_fd;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_img		*player_img;
	t_img		*exit_img;
	t_img		*collectible_img;
	t_img		*wall_img;
	t_img		*ground_img;
	t_game_data	*game_d;
}	t_data;

#endif
