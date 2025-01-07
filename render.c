/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:06:49 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/05 17:31:45 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	render_line(t_fdf *fdf, t_point start, t_point end);
static void	apply_colors(t_fdf *fdf, t_point *point);

// Clear and set the background color of the image. (clear_image())
// For every point, calls render_line() for the right and the bottom points.
void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	clear_image(fdf->img, MAX_PIXEL * 4);
	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
				render_line(fdf, fdf->map->coordinates[x][y],
					fdf->map->coordinates[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				render_line(fdf, fdf->map->coordinates[x][y],
					fdf->map->coordinates[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}

// Actual render pipelilne
// Scale z values
// Apply colors
// Initialize line struct
static void	render_line(t_fdf *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->scale_z;
	end.z *= fdf->cam->scale_z;
	apply_colors(fdf, &start);
	apply_colors(fdf, &end);
	fdf->img->line = init_line(start, end, fdf);
	if (fdf->img->line == NULL)
		close_all(fdf, 6);
	rotate(fdf->cam, fdf->img->line);
	/*
	project(fdf->cam, fdf->img->line);
	transform(fdf->cam, fdf->img->line);
	bresenham(fdf, fdf->img->line->start, fdf->img->line->end);
	*/
	free(fdf->img->line);
}

// Assign color to the lines
// Default is white
// For positive z values - gratient color between grey and orange
// For negative z values - gratient color between grey and blue
static void	apply_colors(t_fdf *fdf, t_point *point)
{
	t_color	*col;

	col = NULL;
	if (fdf->cam->color_pallet == FALSE)
	{
		if (point->color == -1)
			point->color = LINE_DEFAULT;
	}
	else
	{
		if (point->z >= 0)
		{
			col = color_pallet_init(C_GREY, C_ORANGE);
			point->color = get_color(col, absolute(point->z),
					absolute(fdf->map->max_z));
			free(col);
		}
		else
		{
			col = color_pallet_init(C_GREY, C_BLUEY);
			point->color = get_color(col, absolute(point->z),
					absolute(fdf->map->max_z));
			free(col);
		}
	}
}
