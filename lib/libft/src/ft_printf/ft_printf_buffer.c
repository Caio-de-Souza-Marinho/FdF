/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:15:29 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/26 03:41:36 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function is called when
// 1 - the loop is over (format string is over)
// 2 - when buf is full [4k chars]

void	flush_buf(t_data *data)
{
	data->chars_written += write(1, data->buf, data->buffer_index);
	ft_memset(data->buf, 0, BUF_SIZE);
	data->buffer_index = 0;
}

void	write_buf(t_data *data, char c)
{
	if (data->buffer_index == BUF_SIZE)
		flush_buf(data);
	data->buf[data->buffer_index++] = c;
}

void	putchar_buf_n(char c, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision)
	{
		write_buf(data, c);
		precision--;
	}
}

void	putstr_buf_n(char *s, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision && *s != '\0')
	{
		write_buf(data, *s);
		precision--;
		s++;
	}
}

void	itoa_buf(t_data *data, t_union_int int_values)
{
	t_union_int	tmp_int_values;

	if (data->format.is_negative && !data->format.is_converted)
	{
		int_values.int64 = -(int_values.int64);
		data->format.is_converted = 1;
		itoa_buf(data, int_values);
	}
	else if (int_values.uint64 < (unsigned long)data->format.base)
	{
		if (data->format.upper_case)
			data->format.buf_temp[data->format.nbr_len++]
				= UP_HEX[int_values.uint64];
		else
			data->format.buf_temp[data->format.nbr_len++]
				= LOW_HEX[int_values.uint64];
	}
	else
	{
		tmp_int_values.uint64 = int_values.uint64 / data->format.base;
		itoa_buf(data, tmp_int_values);
		tmp_int_values.uint64 = int_values.uint64 % data->format.base;
		itoa_buf(data, tmp_int_values);
	}
}
