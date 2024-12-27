/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:13:05 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/26 03:40:44 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	init_data(t_data *data, const char *format);
static void	render_format(t_data *data);
static void	render_format_c_s(t_data *data, char specifier);

int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.ap, format);
	if (init_data(&data, format))
		return (-1);
	while (*data.s != '\0')
	{
		if (*data.s == '%' && *(data.s++))
		{
			if (parse_format(&data))
			{
				return (-1);
			}
			render_format(&data);
		}
		else
		{
			write_buf(&data, *data.s);
		}
		data.s++;
	}
	flush_buf(&data);
	va_end(data.ap);
	free(data.buf);
	return (data.chars_written);
}

static int	init_data(t_data *data, const char *format)
{
	data->s = format;
	data->chars_written = 0;
	data->buf = malloc(BUF_SIZE * sizeof(char));
	if (data->buf == NULL)
		return (-1);
	ft_memset(data->buf, 0, BUF_SIZE * sizeof(char));
	data->buffer_index = 0;
	return (0);
}

// Wrapper for all rendering functions
static void	render_format(t_data *data)
{
	char		specifier;
	t_union_int	int_values;

	specifier = data->format.specifier;
	int_values.int64 = 0;
	render_format_c_s(data, specifier);
	if (in("pdiuxX", specifier))
	{
		if (in("di", specifier))
		{
			int_values.int64 = (long)va_arg(data->ap, int);
			data->format.signed_value = 1;
			if (int_values.int64 < 0)
				data->format.is_negative = 1;
		}
		else if (in("p", specifier))
			int_values.uint64 = (unsigned long)va_arg(data->ap, void *);
		else if (in("uxX", specifier))
			int_values.uint64 = (unsigned long)va_arg(data->ap, unsigned int);
		printf_int(data, int_values);
	}
}

static void	render_format_c_s(t_data *data, char specifier)
{
	if (specifier == '%')
		printf_char(data, '%');
	else if (specifier == 'c')
		printf_char(data, va_arg(data->ap, int));
	else if (specifier == 's')
		printf_str(data, va_arg(data->ap, char *));
}
