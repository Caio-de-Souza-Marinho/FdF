/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:00:07 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/26 01:16:15 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

/* @brief Outputs the character 'c' to the given file descriptor.
 * 
 * @param c the character to output
 * @param fd the file descriptor on which to write
*/
void	ft_putchar_fd(char c, int fd);

/* @brief Outputs the string 's' to the given file descriptor followed by '\n'.
 *
 * @param s the string to output
 * @param fd the file descriptor on which to write
*/
void	ft_putendl_fd(char *s, int fd);

/* @brief Outputs the integer 'n' to the given file descriptor.
 * 
 * @param n the integer to output
 * @param fd the file descriptor on which to write
*/
void	ft_putnbr_fd(int n, int fd);

/* @brief Outputs the string 's' to the given file descriptor.
 * 
 * @param s the string to output
 * @param fd the file descriptor on which to write
*/
void	ft_putstr_fd(char *s, int fd);

#endif
