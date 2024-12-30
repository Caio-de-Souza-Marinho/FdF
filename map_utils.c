/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 02:32:36 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/30 02:38:05 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->height)
	{
		free(map->points[row]);
		row++;
	}
	free(map->points);
}

int	parse_color(char *value)
{
	char	*comma;

	comma = ft_strchr(value, ',');
	if (comma != NULL)
		return (ft_atoi_base(comma + 1, 16));
	return (DEFAULT_COLOR);
}

int	scale_win(t_map *map, int display_size, char type)
{
	int	res;
	int	max_size;

	res = 0;
	max_size = display_size * 0.8;
	if (type == 'W')
	{
		if (map->width * 10 < max_size)
			return (map->width * 10);
		else
			return (max_size);
	}
	else if (type == 'H')
	{
		if (map->height * 2 < max_size)
			return (map->height * 10);
		else
			return (max_size);
	}
	return (res);
}
