/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:04:37 by caide-so          #+#    #+#             */
/*   Updated: 2024/10/25 18:55:40 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;
	unsigned char	char_c;
	size_t			i;

	i = 0;
	char_s = (unsigned char *)s;
	char_c = (unsigned char)c;
	while (i < n)
	{
		if (char_s[i] == char_c)
			return ((void *)&char_s[i]);
		i++;
	}
	return (NULL);
}
