/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:35:24 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/17 15:27:01 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	create_list(t_listg **list, int fd);
void	append(t_listg **list, char *buf, int fd);
char	*set_line(t_listg *list);
void	clean_list(t_listg **list);

char	*get_next_line(int fd)
{
	static t_listg	*list[1024];
	char			*next_line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(list, fd);
	if (list[fd] == NULL)
	{
		dealloc(&list[fd], NULL, NULL);
		return (NULL);
	}
	next_line = set_line(list[fd]);
	if (next_line == NULL)
	{
		dealloc(&list[fd], NULL, NULL);
		return (NULL);
	}
	clean_list(&list[fd]);
	return (next_line);
}

void	create_list(t_listg **list, int fd)
{
	int		char_read;	
	char	*buf;

	while (!found_newline(list[fd]))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(buf);
			dealloc(&list[fd], NULL, NULL);
			return ;
		}
		if (char_read == 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf, fd);
	}
}

void	append(t_listg **list, char *buf, int fd)
{
	t_listg	*new_node;
	t_listg	*last_node;

	last_node = find_last_node(list[fd]);
	new_node = malloc(sizeof(t_listg));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

char	*set_line(t_listg *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_until_newline(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	clean_list(t_listg **list)
{
	t_listg	*last_node;
	t_listg	*clean_node;
	int		i;
	int		k;
	char	*buf;

	if (list == NULL)
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_listg));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		i++;
	while (last_node->str_buf[i] && last_node->str_buf[i++])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}
