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
	mlx_hook(fdf->win, 2, 1L << 0, &key_press, fdf);
	mlx_hook(fdf->win, 3, 1L << 1, &key_release, fdf);
	mlx_hook(fdf->win, 17, 0, &close_window, fdf);
	mlx_loop_hook(fdf->mlx, &loop_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

static int	close_window(t_fdf *fdf)
{
	close_all(fdf, 0);
	return (0);
}

int	loop_hook(t_fdf *fdf)
{
	if (fdf->keys[KEY_ESC])
		close_all(fdf, 0);
	else if (fdf->keys[KEY_RIGHT] || fdf->keys[KEY_LEFT] || fdf->keys[KEY_UP]
		|| fdf->keys[KEY_DOWN])
		key_translate(-1, fdf);
	else if (fdf->keys[KEY_PLUS] || fdf->keys[KEY_MINUS] || fdf->keys[KEY_Z]
		|| fdf->keys[KEY_X])
		key_scale(-1, fdf);
	else if (fdf->keys[KEY_A] || fdf->keys[KEY_S] || fdf->keys[KEY_D]
		|| fdf->keys[KEY_Q] || fdf->keys[KEY_W] || fdf->keys[KEY_E])
		key_rotate(-1, fdf);
	render(fdf);
	return (0);
}

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode >= 0 && keycode < MAX_KEYS)
	{
		fdf->keys[keycode] = 1;
		if (keycode == KEY_P || keycode == KEY_I || keycode == KEY_O)
			key_project(keycode, fdf);
		else if (keycode == KEY_SPACE)
		{
			if (fdf->cam->color_pallet == FALSE)
				fdf->cam->color_pallet = TRUE;
			else
				fdf->cam->color_pallet = FALSE;
		}
		else if (keycode == KEY_R)
			reset(fdf);
	}
	return (0);
}

int	key_release(int keycode, t_fdf *fdf)
{
	if (keycode >= 0 && keycode < MAX_KEYS)
		fdf->keys[keycode] = 0;
	return (0);
}
