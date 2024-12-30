/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:10:12 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/27 16:19:47 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	cleanup_fdf(t_fdf *fdf);

void	map_error(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

void	img_error(t_fdf *fdf, char *s)
{
	ft_printf("%s\n", s);
	cleanup_fdf(fdf);
	exit(1);
}

void	img_addr_error(t_fdf *fdf, char *s)
{
	ft_printf("%s\n", s);
	cleanup_fdf(fdf);
	exit(1);
}

static void	cleanup_fdf(t_fdf *fdf)
{
	if (fdf->img.img == NULL)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	if (fdf->win == NULL)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	free_map(&fdf->map);
	fdf->img.img = NULL;
	fdf->win = NULL;
	fdf->mlx = NULL;
}
