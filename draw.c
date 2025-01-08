/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:00:25 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/08 19:03:10 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "lib/libft/include/mem.h"

void	pixel_to_image(t_img *image, float x, float y, int color);

// Clears the image and fills it with a background color
void	clear_image(t_img *image, int image_size)
{
	int	x;
	int	y;

	ft_bzero(image->buffer, image_size);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			pixel_to_image(image, x, y, BACKGROUND_DEFAULT);
			x++;
		}
		y++;
	}
}

// Set the color of a single pixel in the image at position (x, y);
void	pixel_to_image(t_img *image, float x, float y, int color)
{
	int	pixel;

	pixel = ((int)y * image->size_line) + ((int)x * 4);
	if (image->endian == 1)
	{
		image->buffer[pixel + 0] = (color >> 24);
		image->buffer[pixel + 1] = (color >> 16) & 0xff;
		image->buffer[pixel + 2] = (color >> 8) & 0xff;
		image->buffer[pixel + 3] = (color) & 0xff;
	}
	else if (image->endian == 0)
	{
		image->buffer[pixel + 0] = (color) & 0xff;
		image->buffer[pixel + 1] = (color >> 8) & 0xff;
		image->buffer[pixel + 2] = (color >> 16) & 0xff;
		image->buffer[pixel + 3] = (color >> 24);
	}
}

void	bresenham(t_fdf *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;
	t_color	*color;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)max(absolute(x_step), absolute(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	color = color_init(start, end);
	if (color == NULL)
		close_all(fdf, 7);
	i_line = 0;
	while (i_line < max_steps)
	{
		start.color = get_color(color, i_line++, max_steps);
		if (start.x > 0 && start.y > 0 && start.x < WINDOW_WIDTH && start.y
      				< WINDOW_HEIGHT)
			pixel_to_image(fdf->img, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
	free(color);
}
