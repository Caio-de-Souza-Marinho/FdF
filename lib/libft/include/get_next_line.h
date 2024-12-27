/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:45:27 by caide-so          #+#    #+#             */
/*   Updated: 2024/10/29 20:45:33 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_listg
{
	char			*str_buf;
	struct s_listg	*next;
}				t_listg;

char		*get_next_line(int fd);
void		create_list(t_listg **list, int fd);
int			found_newline(t_listg *list);
void		append(t_listg **list, char *buf, int fd);
t_listg		*find_last_node(t_listg *list);
char		*set_line(t_listg *list);
int			len_until_newline(t_listg *list);
void		copy_str(t_listg *list, char *str);
void		clean_list(t_listg **list);
void		dealloc(t_listg **list, t_listg *clean_node, char *buf);

#endif
