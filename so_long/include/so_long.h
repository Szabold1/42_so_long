#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
// # include <mlx.h>
// #include <X11/X.h>
// #include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

// structure for holding map data
typedef struct s_map_data {
    char	**map;
    int		rows;
    int     cols;
    int     collect;
    int     exit;
    int     start;
}	t_map_data;

typedef struct s_data {
    void	*mlx_ptr;
    void	*mlx_win;
    void	*mlx_img;
}	t_data;

// File: check_map.c
void	check_map(char *filename);

// File: init.c
bool    init_map_data(t_map_data *map_data, int file);

// File: free.c
void    free_map_data(t_map_data *map_data);

// File: error.c
void	exit_error(char *message);

#endif