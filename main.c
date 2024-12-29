/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:55:09 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/28 04:44:49 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("ERROR: Invalid input\nUsage: .fdf/ <map_file>\n");
		return (1);
	}
	map.path = argv[1];
	init_map(&map);
	free_map(&map);
	return (0);
}

/*
// debug: print the map
for (int row = 0; row < map.height; row++)
{
	for (int col = 0; col < map.width; col++)
	{
		ft_printf("(%d, %d, %d, %#X) ", map.points[row][col].x, 
		map.points[row][col].y, map.points[row][col].z, 
		map.points[row][col].color);
	}
	ft_printf("\n");
}
*/
