/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:10:12 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/28 02:59:58 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_map_dimensions(t_map *map);
static void	allocate_map_points(t_map *map);
static void	parse_map(t_map *map);
static void	parse_line(t_map *map, char *line, int row);

void	init_map(t_map *map)
{
	get_map_dimensions(map);
	allocate_map_points(map);
	parse_map(map);
}

static void	get_map_dimensions(t_map *map)
{
	int		fd;
	char	*line;
	char	**split_line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("Map not found.");
	map->width = 0;
	map->height = 0;
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	while (split_line[map->width] != NULL)
		map->width++;
	free_split(split_line);
	free(line);
	while (line != NULL)
	{
		map->height++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
}

static void	allocate_map_points(t_map *map)
{
	int	row;

	map->points = malloc(sizeof(t_point *) * map->height);
	if (map->points == NULL)
		map_error("Memory allocation failed for map rows.");
	row = 0;
	while (row < map->height)
	{
		map->points[row] = malloc(sizeof(t_point) * map->width);
		if (map->points[row] == NULL)
			map_error("Memory allocation failed for map columns.");
		row++;
	}
}

static void	parse_map(t_map *map)
{
	int		fd;
	int		row;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("ERROR: Map not found.");
	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		parse_line(map, line, row);
		free(line);
		row++;
		line = get_next_line(fd);
	}
	close(fd);
}

static void	parse_line(t_map *map, char *line, int row)
{
	int		col;
	int		col_count;
	char	**split_line;

	split_line = ft_split(line, ' ');
	col_count = 0;
	if (split_line == NULL)
		map_error("Memory allocation failed while splitting the line.");
	col = 0;
	while (split_line[col_count] != NULL)
		col_count++;
	if (col_count != map->width)
	{
		free_split(split_line);
		map_error("ERROR: Inconsistent row lenght in the map");
	}
	while (col < map->width)
	{
		map->points[row][col].x = col;
		map->points[row][col].y = row;
		map->points[row][col].z = ft_atoi(split_line[col]);
		map->points[row][col].color = parse_color(split_line[col]);
		col++;
	}
	free_split(split_line);
}
