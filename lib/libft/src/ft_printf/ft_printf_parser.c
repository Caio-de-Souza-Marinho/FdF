/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:55:54 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/26 03:41:36 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	parse_flags(t_data *data);
static void	get_value(t_data *data, int *value);
static int	ft_atoi_printf(t_data *data);

int	parse_format(t_data *data)
{
	ft_memset(&data->format, 0, sizeof(t_format));
	data->format.precision_value = -1;
	parse_flags(data);
	get_value(data, &data->format.width_value);
	if (*data->s == '.' && *(data->s++))
		get_value(data, &data->format.precision_value);
	if (!in(SPECIFIERS, *data->s))
		return (-1);
	else
	{
		data->format.specifier = *data->s;
		if (in("diu", data->format.specifier))
			data->format.base = 10;
		else if (in("xXp", data->format.specifier))
		{
			data->format.base = 16;
			if (data->format.specifier == 'X')
				data->format.upper_case = 1;
		}
	}
	return (0);
}

static void	parse_flags(t_data *data)
{
	char	flag;

	while (in(FLAGS, *data->s))
	{
		flag = *data->s;
		if (flag == '+')
			data->format.plus = 1;
		else if (flag == '-')
			data->format.left_justified = 1;
		else if (flag == ' ')
			data->format.space = 1;
		else if (flag == '0')
			data->format.zero_pad = 1;
		else if (flag == '#')
			data->format.hash = 1;
		data->s++;
	}
}

static void	get_value(t_data *data, int *value)
{
	if (*data->s == '*')
	{
		*value = va_arg(data->ap, int);
		data->s++;
		return ;
	}
	*value = ft_atoi_printf(data);
}

static int	ft_atoi_printf(t_data *data)
{
	int	value;

	value = 0;
	while (in(NUMBERS, *data->s))
	{
		value = (value * 10) + (*data->s - '0');
		data->s++;
	}
	return (value);
}
