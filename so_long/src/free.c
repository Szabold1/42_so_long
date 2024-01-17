# include "../include/so_long.h"

// free t_map_data structure
void    free_map_data(t_map_data *map_data)
{
    int	i;

    i = 0;
    while (map_data->map && map_data->map[i])
    {
        free(map_data->map[i]);
        i++;
    }
    free(map_data->map);
}