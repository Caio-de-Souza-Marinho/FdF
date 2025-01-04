/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:10:12 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/02 17:21:04 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_width(char *file_name);
static int	get_depth(char *file_name);
static void	get_points(char *file_name, t_map *map);
static void	fill_point(char *point, t_map *map, int coord_x, int coord_y);

t_map	*read_map(char *file_name)
{
	t_map	*map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error(3);
	close(fd);
	map = init_map();
	if (map == NULL)
		return (NULL);
	map->max_x = get_width(file_name);
	map->max_y = get_depth(file_name);
	map->coordinates = init_coordinates(map->max_x, map->max_y);
	if (map->coordinates == NULL)
	{
		free(map);
		return (NULL);
	}
	get_points(file_name, map);
	print_coords("Before center_to_origin", map);
	center_to_origin(map);
	return (map);
}

static int	get_width(char *file_name)
{
	int		fd;
	int		width;
	int		new_width;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	width = ft_word_count(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new_width = ft_word_count(line, ' ');
		if (width != new_width)
			error(4);
		free(line);
	}
	close(fd);
	return (width);
}

static int	get_depth(char *file_name)
{
	int		fd;
	int		depth;
	char	*line;

	fd = open(file_name, O_RDONLY);
	depth = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_isprint(*line))
			depth++;
		free(line);
	}
	close(fd);
	return (depth);
}

static void	get_points(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	char	**split_line;
	int		coord[2];

	fd = open(file_name, O_RDONLY);
	coord[1] = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split_line = ft_split(line, ' ');
		coord[0] = 0;
		while (coord[0] < map->max_x)
		{
			fill_point(split_line[coord[0]], map, coord[0], coord[1]);
			free(split_line[coord[0]]);
			coord[0]++;
		}
		free(split_line);
		free(line);
		coord[1]++;
	}
	close(fd);
}

static void	fill_point(char *point, t_map *map, int coord_x, int coord_y)
{
	char	**info;
	int		i;

	map->coordinates[coord_x][coord_y].x = (float)coord_x;
	map->coordinates[coord_x][coord_y].y = (float)coord_y;
	if (ft_strchr(point, ','))
	{
		info = ft_split(point, ',');
		map->coordinates[coord_x][coord_y].z = (float)ft_atoi(info[0]);
		map->coordinates[coord_x][coord_y].color = ft_atoi_base(info[1], 16);
		i = 0;
		while (info[i])
			free(info[i++]);
		free(info);
	}
	else
	{
		map->coordinates[coord_x][coord_y].z = (float)ft_atoi(point);
		map->coordinates[coord_x][coord_y].color = -1;
	}
	if (map->coordinates[coord_x][coord_y].z > map->max_z)
		map->max_z = map->coordinates[coord_x][coord_y].z;
	if (map->coordinates[coord_x][coord_y].z < map->min_z)
		map->min_z = map->coordinates[coord_x][coord_y].z;
}
