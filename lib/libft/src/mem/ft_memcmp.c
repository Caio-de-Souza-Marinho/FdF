/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:33:09 by caide-so          #+#    #+#             */
/*   Updated: 2024/10/25 18:55:40 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*char_s1;
	unsigned char	*char_s2;
	size_t			i;

	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)char_s1[i] != (unsigned char)char_s2[i])
			return ((unsigned char)char_s1[i] - (unsigned char)char_s2[i]);
		i++;
	}
	return (0);
}
