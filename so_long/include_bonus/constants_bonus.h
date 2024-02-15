/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:07:52 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:07:54 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_BONUS_H
# define CONSTANTS_BONUS_H

# define WIN_MSG "You won! Congratulations!"
# define LOSE_MSG "You lost! You didn't collect all collectibles!"
# define ENEMY_MSG "You lost! You were caught by an enemy!"

# define TILE_SIZE 42
# define MOVES_TEXT_HEIGHT 21

# define PLAYER_PATH "textures/monkey_42.xpm"
# define EXIT_PATH "textures/house_with_garden_42.xpm"
# define COLLECTIBLE_PATH "textures/banana_42.xpm"
# define WALL_PATH "textures/wall_42.xpm"
# define GROUND_PATH "textures/empty_42.xpm"
# define ENEMY_PATH "./textures/snake_42.xpm"

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define GROUND '0'
# define ENEMY 'X'

# define KEY_ESC 0xff1b
# define KEY_UP_ARROW 0xff52
# define KEY_DOWN_ARROW 0xff54
# define KEY_LEFT_ARROW 0xff51
# define KEY_RIGHT_ARROW 0xff53

#endif
