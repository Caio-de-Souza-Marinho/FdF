/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:05:59 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/05 14:03:18 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return (fdf);
}

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

t_cam	*init_cam(t_map *map)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (cam == NULL)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->scale_factor = scale_to_fit(map);
	cam->scale_z = 1;
	cam->move_x = WINDOW_WIDTH / 2;
	cam->move_y = WINDOW_HEIGHT / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	return (cam);
}
