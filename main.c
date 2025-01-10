/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:55:09 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/09 20:55:17 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "lib/minilibx-linux/mlx.h"

static int	expose_handle(t_fdf *fdf);
static int	close_window(t_fdf *fdf);

int	main(int argc, char *argv[])
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	render(fdf);
	mlx_key_hook(fdf->win, &key_handle, fdf);
	mlx_expose_hook(fdf->win, &expose_handle, fdf);
	mlx_hook(fdf->win, 17, 0, &close_window, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

static int	expose_handle(t_fdf *fdf)
{
	render(fdf);
	return (0);
}

static int	close_window(t_fdf *fdf)
{
	close_all(fdf, 0);
	return (0);
}
