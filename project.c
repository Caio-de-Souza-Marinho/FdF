/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:48:12 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/08 21:27:00 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_line *line);
static void	side_parallel(t_line *line);

// Manages which type of projections is applied to the line.
// Projections are ways to represent 3D data on a 2D plane
void	project(t_cam *cam, t_line *line)
{
	if (cam->projection == ISOMETRIC)
		isometric(line);
	else if (cam->projection == SIDE_PARALLEL)
		side_parallel(line);
	else if (cam->projection == TOP)
		return ;
}

static void	isometric(t_line *line)
{
	t_point	new_start;
	t_point new_end;

	new_start.x = (line->start.x - line->start.y) * cos(ANG_30);
	new_start.y = (line->start.x + line->start.y) * sin(ANG_30)
	- line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = (line->end.x - line->end.y) * cos(ANG_30);
	new_end.y = (line->end.x + line->end.y) * sin(ANG_30)
	- line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

static void	side_parallel(t_line *line)
{
	t_point	new_start;
	t_point new_end;

	new_start.x = line->start.y;
	new_start.y = -line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = line->end.y;
	new_end.y = -line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}
