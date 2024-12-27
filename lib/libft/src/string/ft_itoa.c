/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:13:49 by caide-so          #+#    #+#             */
/*   Updated: 2024/10/25 18:55:39 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long num);
static char	*allocate_mem(int len);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;
	long	num;

	num = n;
	len = count_len(num);
	str = allocate_mem(len);
	if (!str)
		return (NULL);
	if (num < 0)
		num = -num;
	i = len - 1;
	while (num != 0)
	{
		str[i] = ((num % 10) + 48);
		num = num / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	return (str);
}

static int	count_len(long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		num = -num;
	}
	if (num == 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*allocate_mem(int len)
{
	char	*tmp;

	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}
