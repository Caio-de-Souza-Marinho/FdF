/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:05:29 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/26 01:25:37 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <stdlib.h>

/* @brief Sets the first 'n' bytes of the memory 's' to zero ('\0'). 
 *
 * @param s a pointer to a memory location
 * @param n the number of bytes to fill with '\0'
 * @return no return.
*/
void	ft_bzero(void *s, size_t n);

/* @brief Allocates memory for an array of 'nmemb' elements of 'size' bytes 
 * each and returns a pointer to the allocated memory.
 * The memory is set to zero. If 'nmemb' or 'size' is 0, then calloc returns 
 * either NULL, or a unique pointer value that can later be successfully 
 * passed to free().
 * 
 * @param nmemb number of elements to be allocated
 * @param size size of each element in bytes
 * @return void* a pointer to the allocated memory, all bytes set to '\0'
*/
void	*ft_calloc(size_t nmemb, size_t size);

/* @brief Scans the initial 'n' bytes of the memory area pointed to by 's' for 
 * the first instance of 'c'.
 * 
 * @param s the memory area to search
 * @param c a char to be search
 * @param n amount of bytes to scan
 * @return A pointer to the matching byte or NULL if the character is not found
 * in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/* @brief Compares the first 'n' bytes, each interpreted as unsigned char, of 
 * the memory areas 's1' and 's2'.
 * 
 * @param s1 a memory area
 * @param s2 another memory area
 * @param n amount of bytes to compare in 's1' and 's2'
 * @return An integer less than, equal to, or greater than zero if the first 
 * 'n' bytes of 's1' is found, respectively, to be less than, to match, or be 
 * greater than the first 'n' bytes of 's2'. If 'n' is zero, the return value 
 * is zero.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* @brief Copies 'n' byes from memory area 'src' to memory area 'dest'. The 
 * memory areas must not overlap.
 *
 * @param dest destination memory area to receive the copy of 'src'
 * @param src source memory area to copy from
 * @param n the number of bytes in 'src' to be copied.
 * @return A pointer to 'dest'.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/* @brief Copies 'n' byes from memory area 'src' to memory area 'dest'. In 
 * case of overlap 'src' will be copied backwards to dst.
 *
 * @param dest destination memory area to receive the copy of 'src'
 * @param src source memory area to copy from
 * @param n the number of bytes in 'src' to be copied.
 * @return A pointer to 'dest'.
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/* @brief Fills the first 'n' bytes of the memory area pointed to by 's' with
 * the int 'c'. 
 *
 * @param s a sequential memory area'
 * @param c char used to fill the bytes in 's'
 * @param n the number of bytes in 's' to fill with 'c'
 * @return A pointer to the memory area s.
*/
void	*ft_memset(void *s, int c, size_t n);

#endif // !MEM_H
