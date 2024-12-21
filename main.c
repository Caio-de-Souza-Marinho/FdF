#include "minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	// init x server
	mlx_ptr = mlx_init();

	// open window
	win_ptr = mlx_new_window(mlx_ptr, 50, 50, "nice");

	
	// testing colors
	int red = 255;
	int green = 0;
	int blue = 127;
	int color = (red << 16) | (green << 8) | blue;

	// draw pixel
	mlx_pixel_put(mlx_ptr, win_ptr, 25, 25, color);

	// handle window events and drawing
	mlx_loop(mlx_ptr);
	return (0);
}
