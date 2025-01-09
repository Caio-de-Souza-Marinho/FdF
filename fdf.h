/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:43:25 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/08 21:36:13 by caide-so         ###   ########.fr       */
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

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 900
# define MAX_PIXEL 1080000

# define C_WHITE	0xffffff
# define C_GREY		0x303030

# define C_RED		0xff0000
# define C_GREEN	0x00ff00
# define C_BLUE		0x0000ff

# define C_ORANGE	0xffa500
# define C_BLUEY	0x0492c2

# define BACKGROUND_DEFAULT C_GREY
# define LINE_DEFAULT C_WHITE
# define C_TEXT C_WHITE

# define ANG_30 0.52359877
# define ANG_1	0.01745329
# define ANG_45 0.78539816

// Enum for projection names and boolean
enum e_projection
{
	ISOMETRIC,
	PERSPECTIVE,
	TOP
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

// menu
void	print_menu(t_fdf *fdf);

# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define KEY_PLUS	61
# define KEY_MINUS	45
# define KEY_SPACE	32

# define KEY_Z		122
# define KEY_X		120
# define KEY_P		112
# define KEY_I		105
# define KEY_O		111
# define KEY_L		108
# define KEY_R		114
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_Q		113
# define KEY_W		119
# define KEY_E		101


#endif
