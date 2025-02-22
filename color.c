/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:02:07 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/08 18:59:12 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	color_gradient(t_color *color, float progress);

// Initializes t_color struct to define a gradient between two colors.
// Extracts each RGB channels
// Calculate deltas, which represent the amount of change needed in each RGB
// channel (red, green, and blue) to transition from the start_color
// to the end_color.
t_color	*color_pallet_init(int min_color, int max_color)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (color == NULL)
		return (NULL);
	color->start_color = min_color;
	color->start_r = (C_RED & min_color) >> 16;
	color->start_g = (C_GREEN & min_color) >> 8;
	color->start_b = (C_BLUE & min_color);
	color->end_color = max_color;
	color->end_r = (C_RED & max_color) >> 16;
	color->end_g = (C_GREEN & max_color) >> 8;
	color->end_b = (C_BLUE & max_color);
	color->delta_r = (color->end_r - color->start_r);
	color->delta_g = (color->end_g - color->start_g);
	color->delta_b = (color->end_b - color->start_b);
	return (color);
}

// Calculates the interpolated color for a specific point (i_line) along
// a line of size (line_size).
int	get_color(t_color *color, int i_line, int line_size)
{
	float	progress;

	progress = (float)i_line / (float)line_size;
	return (color_gradient(color, progress));
}

// Interpolation process
// Calculates the interpolated value for each channel using:
// channel = delta_channel x progress
// delta_channel is the difference between the start and end values for that
// channel.
// proggres determines how far along the gradient we are.
static int	color_gradient(t_color *color, float progress)
{
	int	r;
	int	g;
	int	b;

	r = color->delta_r * progress;
	if (r < -255)
		r = 0;
	else if (r > 255)
		r = 255;
	r = r << 16;
	g = color->delta_g * progress;
	if (g < -255)
		g = 0;
	else if (g > 255)
		g = 255;
	g = g << 8;
	b = color->delta_b * progress;
	if (b < -255)
		b = 0;
	else if (b > 255)
		b = 255;
	return (color->start_color + r + g + b);
}

t_color	*color_init(t_point start, t_point end)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (color == NULL)
		return (NULL);
	color->start_color = start.color;
	color->start_r = (C_RED & start.color) >> 16;
	color->start_g = (C_GREEN & start.color) >> 8;
	color->start_b = (C_BLUE & start.color);
	color->end_color = end.color;
	color->end_r = (C_RED & end.color) >> 16;
	color->end_g = (C_GREEN & end.color) >> 8;
	color->end_b = (C_BLUE & end.color);
	color->delta_r = (color->end_r - color->start_r);
	color->delta_g = (color->end_g - color->start_g);
	color->delta_b = (color->end_b - color->start_b);
	return (color);
}
