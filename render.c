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

static void	apply_isometric_projection(t_map *map, double scale);
static void	iso_proj(t_point *point, double scale);
static void	plot_points(t_fdf *fdf);
static void	put_pixel_to_image(t_img *img, int x, int y, int color);

void	render_map(t_fdf *fdf)
{
	double	scale_x;
	double	scale_y;
	double	scale;

	scale_x = (double)WIN_WIDTH / (fdf->map.width * 10);
	scale_y = (double)WIN_HEIGHT / (fdf->map.height * 10);
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	if (scale < MIN_SCALE)
		scale = MIN_SCALE;
	apply_isometric_projection(&fdf->map, scale);
	plot_points(fdf);
}

static void	apply_isometric_projection(t_map *map, double scale)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			iso_proj(&map->points[i][j], scale);
			j++;
		}
		i++;
	}
}

static void	iso_proj(t_point *point, double scale)
{
	int		x;
	int		y;
	int		z;
	double	angle;

	x = point->x;
	y = point->y;
	z = point->z;
	angle = M_PI / 6;
	point->screen_x = ((y + x) * cos(angle) * scale) + ((double)WIN_WIDTH / 2);
	point->screen_y = ((y - x) * sin(angle) - z) * scale
		+ ((double)WIN_HEIGHT / 2);
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
	int		size_line;
	int		bpp;

	size_line = img->size_line;
	bpp = img->bits_per_pixel;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr + (y * size_line + x * (bpp / 8));
		*(unsigned int *)dst = color;
	}
}
