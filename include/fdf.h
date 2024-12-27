/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:43:25 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/27 16:34:11 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"

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

// errors
void	map_error(char *s);

#endif
