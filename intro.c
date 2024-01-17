#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

// dimensions
# define WIN_WIDTH 800
# define WIN_HEIGHT 450

// error code
# define MLX_ERROR 1

// colors
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

// structure for storing data related to images
typedef struct s_img_data {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

// structure for storing data related to rectangles
typedef struct s_rect_data {
	int	x_start;
	int	y_start;
	int	width;
	int	height;
	int	color;
}	t_rect_data;

// structure for storing data related to MiniLibX
typedef struct s_mlx_data {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_data	img;
}	t_mlx_data;

// function to handle key press events
int	handle_keypress(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	printf("key pressed: %d\n", keysym);
	return (0);
}

void	img_pixel_put(t_img_data img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

// function to draw a rectangle to the screen
int render_rect(t_img_data *img, t_rect_data rect)
{
	int	x;
	int	y;

	y = rect.y_start;
	while (y < rect.y_start + rect.height)
	{
		x = rect.x_start;
		while (x < rect.x_start + rect.width)
			img_pixel_put(img, x++, y, rect.color);
		y++;
	}
	return (0);
}

// function to render the screen
int	render(t_mlx_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	// fill the screen with green
	render_rect(&data->img, (t_rect_data){0, 0, WIN_WIDTH, WIN_HEIGHT, GREEN});
	// create a black and a white rectangle
	render_rect(&data->img, (t_rect_data){100, 100, 100, 100, BLACK});
	render_rect(&data->img, (t_rect_data){200, 200, 100, 100, WHITE});
	// put the image to the window
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	// establish connection to the X server via MiniLibX
	// return the address of a created structure, which will be needed by MiniLibX
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	// create a new window with specified width, height, and title
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "My first window");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}
	// create a new image with specified width and height
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	// get the address of the image and set the values for bits_per_pixel, line_length, and endian
	data.img.addr = mlx_get_data_address(data.img.img_ptr, &data.img.bits_per_pixel,
											&data.img.line_length, &data.img.endian);
	// hooks for event handling
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	// mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	// mlx_key_hook(data.win_ptr, &handle_keyrelease, &data);

	// start the event loop, which keeps the application running and constantly checks for events
	// this loop will exit when the window is closed
	mlx_loop(data.mlx_ptr);
	// destroy MiniLibX display and free memory
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}