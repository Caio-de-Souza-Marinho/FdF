/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:53:09 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/30 20:09:52 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_bresenham(t_bresenham *b, int *coords);
static int	has_reached(int *coords);
static void	bresenham_step(t_bresenham *b, int *coords);
static void	put_pixel_to_image(t_img *img, int x, int y, int color);

void	bresenham(t_img *img, int *coords, int color)
{
	t_bresenham	bresenham;

	init_bresenham(&bresenham, coords);
	while (!has_reached(coords))
	{
		put_pixel_to_image(img, coords[0], coords[1], color);
		bresenham_step(&bresenham, coords);
	}
	put_pixel_to_image(img, coords[0], coords[1], color);
}

static void	init_bresenham(t_bresenham *b, int *coords)
{
	b->dx = abs(coords[2] - coords[0]);
	b->dy = abs(coords[3] - coords[1]);
	if (coords[0] < coords[2])
		b->step_x = 1;
	else
		b->step_x = -1;
	if (coords[1] < coords[3])
		b->step_y = 1;
	else
		b->step_y = -1;
	b->err = b->dx - b->dy;
}

static int	has_reached(int *coords)
{
	return (coords[0] == coords[2] && coords[1] == coords[3]);
}

static void	bresenham_step(t_bresenham *b, int *coords)
{
	int	e2;

	e2 = 2 * b->err;
	if (e2 > -b->dy)
	{
		b->err -= b->dy;
		coords[0] += b->step_x;
	}
	if (e2 < b->dx)
	{
		b->err += b->dx;
		coords[1] += b->step_y;
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
