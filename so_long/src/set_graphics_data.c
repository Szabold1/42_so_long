# include "../include/so_long.h"

// fill t_data structure with initial values
static void	fill_data(t_data *data)
{
	if (!data)
		exit_free(data, "Error\nfill_data() received NULL pointer\n");
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    data->img_ptr = NULL;
	data->player_ptr = NULL;
	data->exit_ptr = NULL;
	data->collect_ptr = NULL;
	data->wall_ptr = NULL;
	data->ground_ptr = NULL;
}

// initialize mlx, window, and image, and data about the image
static void	init_mlx(t_data *data, t_game_data *game_d)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_free(data, "Error\nFailed to initialize mlx\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, game_d->cols * CELL_SIZE,
						game_d->rows * CELL_SIZE, "so_long");
	if (!data->win_ptr)
		exit_free(data, "Error\nFailed to create window\n");
	data->img_ptr = (t_img *)malloc(sizeof(t_img));
	if (!data->img_ptr)
		exit_free(data, "Error\nmalloc returned NULL\n");
	data->img_ptr->ptr = mlx_new_image(data->mlx_ptr,
						game_d->cols * CELL_SIZE, game_d->rows * CELL_SIZE);
	if (!data->img_ptr->ptr)
		exit_free(data, "Error\nFailed to create image\n");
	data->img_ptr->addr = mlx_get_data_addr(data->img_ptr->ptr,
							&data->img_ptr->bits_per_pixel,
							&data->img_ptr->line_len, &data->img_ptr->endian);
	if (!data->img_ptr->addr)
		exit_free(data, "Error\nFailed to get image address\n");
}

// load a texture from a file (path) into img
static void	load_texture(t_data *data, t_game_data *game_d, t_img **img, char *path)
{
	*img = (t_img *)malloc(sizeof(t_img));
	if (!(*img))
		exit_free(data, "Error\nmalloc returned NULL\n");
	(*img)->ptr = mlx_xpm_file_to_image(data->mlx_ptr, path,
										&(*img)->width, &(*img)->height);
	if (!(*img)->ptr)
		exit_free(data, "Error\nFailed to load texture\n");
	(*img)->addr = mlx_get_data_addr((*img)->ptr, &(*img)->bits_per_pixel,
									&(*img)->line_len, &(*img)->endian);
	if (!(*img)->addr)
		exit_free(data, "Error\nFailed to get texture address\n");
}

// load textures from files (path) into t_data structure
static void	init_textures(t_data *data, t_game_data *game_d)
{
	load_texture(data, game_d, &data->player_ptr, PLAYER_PATH);
	load_texture(data, game_d, &data->exit_ptr, EXIT_PATH);
	load_texture(data, game_d, &data->collect_ptr, COLLECTIBLE_PATH);
	load_texture(data, game_d, &data->wall_ptr, WALL_PATH);
	load_texture(data, game_d, &data->ground_ptr, GROUND_PATH);
}

// fill t_data structure and initialize graphics (mlx and textures)
// return t_data structure if successful, exit otherwise
t_data	*set_graphics_data(t_data *data)
{
	fill_data(data);
	init_mlx(data, data->game_d);
	init_textures(data, data->game_d);
	return (data);
}
