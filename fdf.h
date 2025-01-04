/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:43:25 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/02 03:24:35 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/libft/include/libft.h"
# include "lib/minilibx-linux/mlx.h"

// perror
# include <stdio.h>

// math
# include <math.h>

# define WINDOW_WIDTH 1020
# define WINDOW_HEIGHT 900

// STRUCTS

// Single point struct: x, y, z and color values for each point in the map.
typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

// Map struct: holds information on the map parsed, such as a matrix with
// all points coordinates, total width, height and depth values.
typedef struct s_map
{
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}	t_map;

// Current line being printed.
typedef struct s_line
{
	t_point	start;
	t_point	end;
	float	transform_z;
}	t_line;

// Image struct: holds information on the image pointers given by MiniLibX
// and the buffer pointer fron which the final image is printed, besides
// the current line to be transfered to the buffer.
typedef struct s_img
{
	void	*img;
	char	*buffer;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_line	*line;
}	t_img;

// Camera struct: holds information about the displayed image, such as
// type of projection, scale, translation delta and angle values for
// rotation on the three axes.
typedef struct s_cam
{
	int		projection;
	float	scale_factor;
	float	scale_z;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

// Fdf struct: holds all information necessary for the fdf to run.
typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	t_map	*map;
	t_img	*img;
	t_cam	*cam;
}	t_fdf;

// Functions

// initialize structs
t_fdf	*init_fdf(char *file_name);
t_map	*init_map(void);
t_point	**init_coordinates(int width, int depth);

// read
t_map	*read_map(char *file_name);

// map utils
void	center_to_origin(t_map *map);

// errors
void	error(int exit_code);

// render
void	render_map(t_fdf *fdf);

// draw
void	draw(t_fdf *fdf);

// bresenham
void	bresenham(t_img *img, int *coords, int color);

// debug
void	print_coords(char *s, t_map *map);

#endif
