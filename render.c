/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:06:49 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/30 01:57:32 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric_projection(t_point *point);
static void	apply_isometric_projection(t_map *map);
static void	plot_points(t_fdf *fdf);
static void	put_pixel_to_image(t_img *img, int x, int y, int color);

void	render_map(t_fdf *fdf)
{
	apply_isometric_projection(&fdf->map);
	plot_points(fdf);
}

static void	apply_isometric_projection(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			isometric_projection(&map->points[i][j]);
			j++;
		}
		i++;
	}
}

static void	isometric_projection(t_point *point)
{
	int		x;
	int		y;
	int		z;
	double	angle;

	x = point->x;
	y = point->y;
	z = point->z;
	angle = M_PI / 6;
	point->screen_x = (x - y) * cos(angle) + ((double)WIN_WIDTH / 2);
	point->screen_y = (x + y) * sin(angle) - z + ((double)WIN_HEIGHT / 2);
}

static void	plot_points(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			put_pixel_to_image(&fdf->img, 
		      fdf->map.points[i][j].screen_x,
		      fdf->map.points[i][j].screen_y,
		      fdf->map.points[i][j].color);
			j++;
		}
		i++;
	}
}

static void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
