/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:55:09 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/08 19:10:08 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	render(fdf);
	mlx_loop(fdf->mlx);
	//free_fdf(fdf);
	return (0);
}

/*
// debug: print the map coordinates
void	print_coords(char *s, t_map *map)
{
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

static void	free_fdf(t_fdf *fdf)
{
	int	x;

	if (fdf)
	{
		if (fdf->map)
		{
			if (fdf->map->coordinates)
			{
				x = 0;
				while (x < fdf->map->max_x)
				{
					free(fdf->map->coordinates[x]);
					x++;
				}
				free(fdf->map->coordinates);
			}
			free(fdf->map);
		}
		free(fdf);
	}
}
*/
