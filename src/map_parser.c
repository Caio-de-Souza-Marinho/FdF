/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:10:12 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/27 16:31:10 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_map_dimensions(t_map *map);

void	init_map(t_map *map)
{
	get_map_dimensions(map);
}

void	get_map_dimensions(t_map *map)
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
	while (line != NULL)
	{
		map->height++;
		line = get_next_line(fd);
	}
	ft_printf("map w: %d\n", map->width);
	ft_printf("map h: %d\n", map->height);
	close(fd);

}
