/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:10:12 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/01 19:45:49 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int exit_code)
{
	if (exit_code == 0)
		ft_printf("FdF closed.\n");
	else if (exit_code == 1)
		ft_printf("Usage: .fdf/ <map_file>\n");
	else if (exit_code == 2)
		ft_printf("Cannot initialize fdf\n");
	else if (exit_code == 3)
		ft_printf("Map not found\n");
	else if (exit_code == 4)
		ft_printf("Found wrong line length. Exiting.\n");
	exit(exit_code);
}
