/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:00:25 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/30 20:17:19 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_img *img, t_point *p1, t_point *p2);

void	draw(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			if (j < fdf->map.width - 1)
				draw_line(&fdf->img, &fdf->map.points[i][j],
					&fdf->map.points[i][j + 1]);
			if (i < fdf->map.height - 1)
				draw_line(&fdf->img, &fdf->map.points[i][j],
					&fdf->map.points[i + 1][j]);
			j++;
		}
		i++;
	}
}

static void	draw_line(t_img *img, t_point *p1, t_point *p2)
{
	int	coords[4];

	coords[0] = p1->screen_x;
	coords[1] = p1->screen_y;
	coords[2] = p2->screen_x;
	coords[3] = p2->screen_y;
	bresenham(img, coords, p1->color);
}
