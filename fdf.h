/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:43:25 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/09 20:45:33 by caide-so         ###   ########.fr       */
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

# include "colors.h"
# include "keys.h"

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 900
# define MAX_PIXEL 1080000

# define BACKGROUND_DEFAULT C_BLACK
# define LINE_DEFAULT C_WHITE
# define C_TEXT C_WHITE

# define ANG_30 0.52359877
# define ANG_1	0.01745329
# define ANG_45 0.78539816

# define MAX_KEYS 65536

// Enum for projection names and boolean
enum e_projection
{
	ISOMETRIC,
	SIDE_PARALLEL,
	TOP,
};

enum e_bool
{
	FALSE,
	TRUE
};

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

// Color struct: valid for line.
typedef struct s_color
{
	int	start_color;
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_color;
	int	end_r;
	int	end_g;
	int	end_b;
	int	delta_r;
	int	delta_g;
	int	delta_b;
}	t_color;

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
	int		color_pallet;
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
	int		keys[MAX_KEYS];
}	t_fdf;

// Functions

// initialize structs
t_fdf	*init_fdf(char *file_name);
t_map	*init_map(void);
t_point	**init_coordinates(int width, int depth);
t_img	*init_image(void *mlx);
t_cam	*init_cam(t_map *map);
t_line	*init_line(t_point start, t_point end, t_fdf *fdf);

// read
t_map	*read_map(char *file_name);

// map utils
void	center_to_origin(t_map *map);
float	scale_to_fit(t_map *map);
void	reset(t_fdf *fdf);

// errors
void	error(int exit_code);

// render
void	render(t_fdf *fdf);

// draw
void	clear_image(t_img *image, int image_size);
void	pixel_to_image(t_img *image, float x, float y, int color);
void	bresenham(t_fdf *fdf, t_point start, t_point end);

// debug
void	print_coords(char *s, t_map *map);

// close
void	close_map(t_fdf *fdf, int exit_code);
void	close_all(t_fdf *fdf, int exit_code);

// utils
float	min(float a, float b);
float	absolute(float nbr);
float	max(float a, float b);

// color
t_color	*color_pallet_init(int min_color, int max_color);
int		get_color(t_color *color, int i_line, int line_size);
t_color	*color_init(t_point start, t_point end);

// rotate
void	rotate(t_cam *cam, t_line *line);
void	rotate_x(t_line *line, double angle);
void	rotate_y(t_line *line, double angle);
void	rotate_z(t_line *line, double angle);

// projection
void	project(t_cam *cam, t_line *line);

// transform
void	transform(t_cam *cam, t_line *line);
void	scale(t_line *line, int scale_factor);
void	translate(t_line *line, int move_x, int move_y);

// hooks
int		key_handle(int keycode, t_fdf *fdf);
int		key_press(int keycode, t_fdf *fdf);
int		key_release(int keycode, t_fdf *fdf);
int		loop_hook(t_fdf *fdf);

// menu
void	print_menu(t_fdf *fdf);

// key handlers
void	key_translate(int keycode, t_fdf *fdf);
void	key_scale(int keycode, t_fdf *fdf);
void	key_rotate(int keycode, t_fdf *fdf);
void	key_project(int keycode, t_fdf *fdf);

#endif
