/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:26:04 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/08 21:20:53 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_translate(int keycode, t_fdf *fdf)
{
	int	step;

	step = 3;
	if (keycode == KEY_RIGHT || (keycode == -1 && fdf->keys[KEY_RIGHT]))
		fdf->cam->move_x += step;
	else if (keycode == KEY_LEFT || (keycode == -1 && fdf->keys[KEY_LEFT]))
		fdf->cam->move_x -= step;
	else if (keycode == KEY_DOWN || (keycode == -1 && fdf->keys[KEY_DOWN]))
		fdf->cam->move_y += step;
	else if (keycode == KEY_UP || (keycode == -1 && fdf->keys[KEY_UP]))
		fdf->cam->move_y -= step;
}

void	key_scale(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS || (keycode == -1 && fdf->keys[KEY_PLUS]))
		fdf->cam->scale_factor += 1;
	else if (keycode == KEY_MINUS || (keycode == -1 && fdf->keys[KEY_MINUS]))
		fdf->cam->scale_factor -= 1;
	else if ((keycode == KEY_Z && fdf->cam->scale_z > -1)
		|| (keycode == -1 && fdf->keys[KEY_Z] && fdf->cam->scale_z > -1))
		fdf->cam->scale_z -= 0.1;
	else if ((keycode == KEY_X && fdf->cam->scale_z < 1)
		|| (keycode == -1 && fdf->keys[KEY_X] && fdf->cam->scale_z < 1))
		fdf->cam->scale_z += 0.1;
}

void	key_rotate(int keycode, t_fdf *fdf)
{
	double	step;

	step = 2 * ANG_1;
	if (keycode == KEY_S || (keycode == -1 && fdf->keys[KEY_S]))
		fdf->cam->alpha -= step;
	else if (keycode == KEY_W || (keycode == -1 && fdf->keys[KEY_W]))
		fdf->cam->alpha += step;
	else if (keycode == KEY_A || (keycode == -1 && fdf->keys[KEY_A]))
		fdf->cam->gamma -= step;
	else if (keycode == KEY_D || (keycode == -1 && fdf->keys[KEY_D]))
		fdf->cam->gamma += step;
	else if (keycode == KEY_Q || (keycode == -1 && fdf->keys[KEY_Q]))
		fdf->cam->beta -= step;
	else if (keycode == KEY_E || (keycode == -1 && fdf->keys[KEY_E]))
		fdf->cam->beta += step;
}

void	key_project(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_P || (keycode == -1 && fdf->keys[KEY_P]))
		fdf->cam->projection = SIDE_PARALLEL;
	else if (keycode == KEY_I || (keycode == -1 && fdf->keys[KEY_I]))
		fdf->cam->projection = ISOMETRIC;
	else if (keycode == KEY_O || (keycode == -1 && fdf->keys[KEY_O]))
		fdf->cam->projection = TOP;
}
