/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 02:32:36 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/28 04:43:17 by caide-so         ###   ########.fr       */
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
