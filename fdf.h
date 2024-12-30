/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:43:25 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/28 04:43:27 by caide-so         ###   ########.fr       */
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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
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
	t_img	img;
	t_map	map;
}	t_fdf;

// map
void	init_map(t_map *map);

// map utils
void	free_split(char **split);
void	free_map(t_map *map);
int		parse_color(char *value);

// errors
void	map_error(char *s);
void	img_error(t_fdf *fdf, char *s);
void	img_addr_error(t_fdf *fdf, char *s);

#endif
