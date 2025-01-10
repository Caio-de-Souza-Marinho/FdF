/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:05:45 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/28 03:43:16 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	is_blank(char c);
static int	is_valid(char c, int base);
static int	value_of(char c);

int	ft_atoi_base(char *str, int base)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (is_blank(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (base == 16 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i += 2;
	while (is_valid(str[i], base))
	{
		result = result * base + value_of(str[i]);
		i++;
	}
	return (result * sign);
}

static int	is_blank(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

static int	is_valid(char c, int base)
{
	char	*symbols1;
	char	*symbols2;

	symbols1 = "0123456789abcdef";
	symbols2 = "0123456789ABCDEF";
	while (base--)
		if (symbols1[base] == c || symbols2[base] == c)
			return (1);
	return (0);
}

static int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

/*
int	ft_convert_from_base(char *str, char *base);
int	ft_check_base_error(char *str);

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		total;
	size_t	i;

	if (!ft_check_base_error(base))
		return (0);
	sign = 1;
	total = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	if (str[i] == '0')
	{
		i++;
		if (str[i] == 'x')
			i++;
	}
	total = ft_convert_from_base(&str[i], base);
	return (total * sign);
}

int	ft_convert_from_base(char *str, char *base)
{
	size_t	i;
	size_t	c;
	int		total;
	int		base_len;

	i = 0;
	total = 0;
	base_len = ft_strlen(base);
	while (str[i] && ft_strchr(base, ft_tolower(str[i])))
	{
		c = 0;
		while (base[c] != ft_tolower(str[i]) && base[c])
			c++;
		total = (total * base_len) + c;
		i++;
	}
	return (total);
}

int	ft_check_base_error(char *str)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i])
	{
		if (!ft_isprint(str[i]))
			return (0);
		c = 1;
		while (str[i + c])
		{
			if (str[i + c] == str[i])
				return (0);
			c++;
		}
		i++;
	}
	return (1);
}
*/
