/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:19:22 by caide-so          #+#    #+#             */
/*   Updated: 2024/10/25 18:55:40 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*char_src;
	unsigned char	*char_dest;
	size_t			i;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	i = 0;
	char_src = (unsigned char *)src;
	char_dest = (unsigned char *)dest;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
