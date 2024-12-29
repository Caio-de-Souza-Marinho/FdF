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

// map
void	init_map(t_map *map);
void	get_map_dimensions(t_map *map);
void	allocate_map_points(t_map *map);
void	parse_map(t_map *map);
void	parse_line(t_map *map, char *line, int row);

// map utils
void	free_split(char **split);
void	free_map(t_map *map);
int		parse_color(char *value);

// errors
void	map_error(char *s);

#endif
