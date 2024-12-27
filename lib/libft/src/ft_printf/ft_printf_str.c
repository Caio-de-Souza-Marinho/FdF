/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:34:51 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/26 03:41:36 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_str_padding_spaces(t_data *data, char *s);

// [-][width][.precision]
void	printf_str(t_data *data, char *s)
{
	if (s == NULL)
		s = "(null)";
	set_str_padding_spaces(data, s);
	if (data->format.left_justified)
	{
		if (data->format.precision_value >= 0)
			putstr_buf_n(s, data->format.precision_value, data);
		else
			putstr_buf_n(s, s_len(s), data);
		putchar_buf_n(' ', data->format.padding_spaces, data);
	}
	else
	{
		putchar_buf_n(' ', data->format.padding_spaces, data);
		if (data->format.precision_value >= 0)
			putstr_buf_n(s, data->format.precision_value, data);
		else
			putstr_buf_n(s, s_len(s), data);
	}
}

static void	set_str_padding_spaces(t_data *data, char *s)
{
	int	len;

	len = s_len(s);
	if (data->format.width_value > 0)
	{
		if (data->format.precision_value >= 0)
		{
			if (data->format.precision_value > len)
				data->format.padding_spaces = data->format.width_value - len;
			else if (data->format.precision_value < len)
			{
				data->format.padding_spaces = data->format.width_value - \
				data->format.precision_value;
			}
		}
		else
		{
			data->format.padding_spaces = data->format.width_value - len;
		}
	}
}
