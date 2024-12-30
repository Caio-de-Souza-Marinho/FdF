/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:55:09 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/30 02:39:23 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "lib/minilibx-linux/mlx.h"

static int	init_window(t_fdf *fdf);
static void	init_img(t_fdf *fdf);

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2)
	{
		ft_printf("ERROR: Invalid input\nUsage: .fdf/ <map_file>\n");
		return (1);
	}
	fdf.map.path = argv[1];
	init_map(&fdf.map);
	if (!init_window(&fdf))
	{
		ft_printf("ERROR: Failed to initialize the window\n");
		free_map(&fdf.map);
		return (1);
	}
	render_map(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
	mlx_loop(fdf.mlx);
	free_map(&fdf.map);
	return (0);
}

static int	init_window(t_fdf *fdf)
{
	/*
	int	screen_width;
	int	screen_height;
	int	win_width;
	int	win_height;
	*/

	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
	{
		ft_printf("ERROR: MLX initialization failed\n");
		return (0);
	}
	//mlx_get_screen_size(fdf->mlx, &screen_width, &screen_height);
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (fdf->win == NULL)
	{
		free(fdf->mlx);
		ft_printf("ERROR: Window creation failed\n");
		return (0);
	}
	init_img(fdf);
	return (1);
}

static void	init_img(t_fdf *fdf)
{
	int	bpp;
	int	size_line;
	int	endian;

	//fdf->img.img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	fdf->img.img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (fdf->img.img == NULL)
		img_error(fdf, "ERROR: Image creation failed\n");
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &bpp, &size_line, &endian);
	if (fdf->img.addr == NULL)
		img_addr_error(fdf, "ERROR: Failed to get image data address\n");
	fdf->img.bits_per_pixel = bpp;
	fdf->img.size_line = size_line;
	fdf->img.endian = endian;
}

/*
// debug: print the map
for (int row = 0; row < map.height; row++)
{
	for (int col = 0; col < map.width; col++)
	{
		ft_printf("(%d, %d, %d, %#X) ", map.points[row][col].x, 
		map.points[row][col].y, map.points[row][col].z, 
		map.points[row][col].color);
	}
	ft_printf("\n");
}
*/
