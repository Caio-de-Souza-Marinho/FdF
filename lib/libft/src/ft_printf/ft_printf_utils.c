/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:12:23 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/26 03:41:36 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in(const char *s, char c)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	s_len(const char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len])
	{
		len++;
	}
	return (len);
}
