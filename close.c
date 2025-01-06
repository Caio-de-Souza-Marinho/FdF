/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:54:33 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/05 17:09:48 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	close_coordinates(t_point **coordinates, int width);

void	close_map(t_fdf *fdf, int exit_code)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf);
	error(exit_code);
}

static void	close_coordinates(t_point **coordinates, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
}

void	close_all(t_fdf *fdf, int exit_code)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	free(fdf->img);
	free(fdf->cam);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	error(exit_code);
}
