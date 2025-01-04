/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:55:09 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/01 19:17:52 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_coords(char *s, t_map *map);

int	main(int argc, char *argv[])
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	print_coords("After center_to_origin", fdf->map);
	//render(fdf);
	//mlx_loop(fdf->mlx);
	return (0);
}

void	print_coords(char *s, t_map *map)
{
	// debug: print the map
	printf("%s\n", s);
	for (int y = 0; y < map->max_y; y++)
	{
		for (int x = 0; x < map->max_x; x++)
		{
			printf("(%f, %f, %f, %d) ",
	     			map->coordinates[x][y].x, 
	     			map->coordinates[x][y].y,
	     			map->coordinates[x][y].z, 
	     			map->coordinates[x][y].color);
		}
		printf("\n");
	}
}
