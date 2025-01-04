/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:28:16 by caide-so          #+#    #+#             */
/*   Updated: 2024/10/25 18:55:39 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated;
	size_t	total_size;
	size_t	size_max;
	size_t	i;

	size_max = ((size_t) ~(size_t) 0);
	if (size != 0 && nmemb > size_max / size)
		return (NULL);
	total_size = nmemb * size;
	allocated = malloc(total_size);
	if (!allocated)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((unsigned char *)allocated)[i] = 0;
		i++;
	}
	return (allocated);
}
