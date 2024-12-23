#include "minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	// init x server
	mlx_ptr = mlx_init();

	int win_x = 200;
	int win_y = 200;
	// open window
	win_ptr = mlx_new_window(mlx_ptr, win_x, win_y, "mlx study");
	
	// testing colors
	int red = 255;
	int green = 0;
	int blue = 0;
	int color = (red << 16) | (green << 8) | blue;

	// draw a vertical line 
	int v_line_x = 0;
	int v_line_y = 100;
	int i = 0 ;
	while (i < 200)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, v_line_x, v_line_y, color);
		v_line_x++;
		i++;
	}

	// draw a vertical line 
	int pixel_start_x = 100;
	int pixel_start_y = 0;
	i = 0 ;
	while (i < 200)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pixel_start_x, pixel_start_y, color);
		pixel_start_y++;
		i++;
	}
	// handle window events and drawing
	mlx_loop(mlx_ptr);
	return (0);
}
