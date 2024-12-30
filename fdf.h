/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:43:25 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/30 20:11:13 by caide-so         ###   ########.fr       */
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

# ifndef WIN_WIDTH 
#  define WIN_WIDTH 1024
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 768
# endif

# ifndef DEFAULT_COLOR
#  define DEFAULT_COLOR 0xFFFFFF
# endif

# ifndef MIN_SCALE
#  define MIN_SCALE 1.0
# endif

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	screen_x;
	int	screen_y;
}	t_point;

typedef struct s_map
{
	char	*path;
	int		width;
	int		height;
	t_point	**points;
	int		**colors;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	t_img	img;
	t_map	map;
}	t_fdf;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	err;
	int	step_x;
	int	step_y;
}	t_bresenham;

// map
void	init_map(t_map *map);

// map utils
void	free_split(char **split);
void	free_map(t_map *map);
int		parse_color(char *value);
int		scale_win(t_map *map, int display_size, char type);

// errors
void	map_error(char *s);
void	img_error(t_fdf *fdf, char *s);
void	img_addr_error(t_fdf *fdf, char *s);

// render
void	render_map(t_fdf *fdf);

// draw
void	draw(t_fdf *fdf);

// bresenham
void	bresenham(t_img *img, int *coords, int color);

#endif
