/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:05:59 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/05 23:02:24 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Allocates memory for the t_fdf struct
// Reads and parses the map file into the t_map struct
// Initializes MLX pointers (mlx and win)
t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		error(2);
	fdf->map = read_map(file_name);
	if (fdf->map == NULL)
	{
		free(fdf);
		error(4);
	}
	fdf->mlx = mlx_init();
	fdf->win_x = WINDOW_WIDTH;
	fdf->win_y = WINDOW_HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, "FdF");
	fdf->img = init_image(fdf->mlx);
	if (fdf->img == NULL)
		close_map(fdf, 5);
	fdf->cam = init_cam(fdf->map);
	if (fdf->cam == NULL)
		close_all(fdf, 6);
	ft_bzero(fdf->keys, sizeof(fdf->keys));
	return (fdf);
}

// Allocates memory for the t_map struct and initializes metadata
t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->coordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	return (map);
}

// Allocates memory for a t_img struct and use MLX functions to create an
// image buffer and access its memory.
t_img	*init_image(void *mlx)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (image == NULL)
		return (NULL);
	image->img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->buffer = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->size_line, &image->endian);
	image->line = NULL;
	return (image);
}

// Allocates memory for a t_cam struct
// Initializes the camera with default settings (projection, color pallet,
// scale factor, position and rotation angles.
t_cam	*init_cam(t_map *map)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (cam == NULL)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->color_pallet = FALSE;
	cam->scale_factor = scale_to_fit(map);
	cam->scale_z = 1;
	cam->move_x = WINDOW_WIDTH / 2;
	cam->move_y = WINDOW_HEIGHT / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	return (cam);
}

// Gets information from start and end t_point structs
// Calculate transform z.
// transform_z = max(vertical extend, horizontal extent)
// This determines the largest value among the vertical range and 
// horizontal range.
t_line	*init_line(t_point start, t_point end, t_fdf *fdf)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (line == NULL)
		return (NULL);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	line->transform_z = max((fdf->map->max_z - fdf->map->min_z),
			max(fdf->map->max_x, fdf->map->max_y));
	return (line);
}
