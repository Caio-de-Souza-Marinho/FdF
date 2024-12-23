#include <stdlib.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"

#define ESC_KEY 65307 // Key code for ESC on most systems

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
} 	t_vars;

int	deal_key(int key, void *param);
void	ft_putstr(char *str);

int	main(void)
{
	t_vars vars;

	// Initialize MiniLibX
	vars.mlx_ptr = mlx_init(); // init x server
	//
	// open window
	int win_x = 200;
	int win_y = 200;
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, win_x, win_y, "mlx study");
	
	// colors
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
		mlx_pixel_put(vars.mlx_ptr, vars.win_ptr, v_line_x, v_line_y, color);
		v_line_x++;
		i++;
	}

	// draw a horizontal line 
	int pixel_start_x = 100;
	int pixel_start_y = 0;
	i = 0 ;
	while (i < 200)
	{
		mlx_pixel_put(vars.mlx_ptr, vars.win_ptr, pixel_start_x, pixel_start_y, color);
		pixel_start_y++;
		i++;
	}

	// key hook event - press a key to trigger an event
	mlx_key_hook(vars.win_ptr, deal_key, &vars);

	// handle window events and drawing
	mlx_loop(vars.mlx_ptr);
	return (0);
}

int	deal_key(int key, void *param)
{
	t_vars *vars = (t_vars *)param;

	if (key == ESC_KEY)
	{
		mlx_destroy_window((void *)vars->mlx_ptr, vars->win_ptr);
		ft_putstr("ESC pressed\n");
		exit(0);
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
