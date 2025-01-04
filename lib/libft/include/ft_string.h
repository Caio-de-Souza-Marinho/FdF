/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:16:55 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/01 20:49:15 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

/* @brief Converts the initial portion of the string pointed to by nptr to int. 
 *
 * @param nptr a string to convert
 * @return int with the converted value.
*/
int		ft_atoi(const char *nptr);

/* @brief Allocates with malloc and returns a string representing the integer 
 * received as an argument. Negative numbers must be handled.
 * 
 * @param n the integer to convert
 * @return The string representing the integer. NULL if the allocation fails.
*/
char	*ft_itoa(int n);

/* @brief Allocates with malloc and returns an array of strings obtained by 
 * splitting 's' using the character 'c' as a delimiter. 
 * The array must end with a NULL pointer.
 * 
 * @param s the string to be split
 * @param c the delimiter character
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
*/
char	**ft_split(char const *s, char c);

/* @brief Looks for the first occurrence of the char 'c' in the string 's'.
 * 
 * @param s a string
 * @param c a char to be searched for in 's'
 * @return A pointer to the matched character or NULL if the character is not 
 * found. The terminating null byte is considered part of the string.
*/
char	*ft_strchr(const char *s, int c);

/* @brief Duplicates the contents of string 's' using malloc.
 * 
 * @param s a string
 * @return char* a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available.
*/
char	*ft_strdup(const char *s);

/* @brief Applies the function 'f' on each character of the string passed as 
 * argument, passing its index as first argument. Each character is passed by 
 * address to 'f' to be modified if necessary.
 * 
 * @param s the string on which to iterate
 * @param f the function to apply to each character
 * @return The modified string.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* @brief Allocates with malloc and returns a new string, which is the result 
 * of the concatenation of 's1' and 's2'.
 * 
 * @param s1 the prefix string
 * @param s2 the suffix string
 * @return The new string. NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/* @brief Appends the NULL-terminated string 'src' to the end of 'dst'.
 * NULL-terminating the result.
 *
 * @param dst destination string to receive 'src' at the end
 * @param src source string to be appended at the end of 'dst'
 * @param size the number of bytes to append from 'src' to 'dst'
 * @return The total length of the string it tried to create.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* @brief Copies size - 1 chars from the NULL-terminated string 'src' to 'dst',
 * NULL-terminating the result.
 *
 * @param dst destination string to receive the copy of 'src'
 * @param src source string to copy from
 * @param size the number of bytes to copy from 'src' to 'dst'
 * @return The total length of the string it tried to create.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* @brief Calculates the length of the string pointed to by 's'. 
 *
 * @param s as a true c string, terminated by '\0'
 * @return the number of chars in the string.
*/
size_t	ft_strlen(const char *s);

/* @brief Applies the function 'f' to each character of the string 's', and 
 * pass its index as first argument to create a new string with malloc, 
 * resulting from successive applications of 'f'.
 * 
 * @param s the string on which to iterate
 * @param f the function to apply to each character
 * @return The string created from the successive applications of ’f’. 
 * Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* @brief Compares the first 'n' bytes of two strings, 's1' and 's2'.
 * 
 * @param s1 a string
 * @param s2 a string
 * @param the amount of bytes to compare
 * @return An integer less than, equal to, or greater than zero if 's1' is 
 * found, respectively, to be less than, to match, or be greater than 's2'.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* @brief Locates the first occurrence of the null-terminated string little in 
 * the string big, where not more than len characters are searched. Characters 
 * that appear after a '\0' character are not searched.
 * 
 * @param big a string to be searched through
 * @param little a substring to be located in big
 * @param len amount of characters to search
 * @return If 'little' is an empty string, 'big' is returned; 
 * if 'little' occurs nowhere in 'big', NULL is returned; 
 * otherwise a pointer to the first character of the first occurrence of 
 * 'little' is returned.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* @brief Looks for the last occurrence of the character 'c' in the string 's'.
 * 
 * @params a string
 * @param c a char to be searched for in 's'
 * @return A pointer to the matched character or NULL if the character is not 
 * found. The terminating null byte is considered part of the string.
*/
char	*ft_strrchr(const char *s, int c);

/* @brief Allocates with malloc and returns a copy of 's1' with the characters 
 * specified in 'set' removed from the beginning and the end of the string.
 * 
 * @param s1 the string to be trimmed
 * @param set the reference set of characters to trim
 * @return The trimmed string. NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set);

/* @brief Allocates with malloc and returns a substring from the string 's'. 
 * The substring begins at index 'start' and is of maximum size 'len'.
 * 
 * @param s the string from which to create the substring
 * @param start the start index of the substring in the string 's'
 * @param len the maximum length of the substring
 * @return The substring. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* @brief Converts uppercase letters to lowercase.
 *
 * @param c the character
 * @return The converted letter or 'c' if the conversion was not possible.
*/
int		ft_tolower(int c);

/* @brief Converts lowercase letters to uppercase.
 *
 * @param c the character
 * @return The converted letter or 'c' if the conversion was not possible.
*/
int		ft_toupper(int c);

/* @brief Converts a string to an integer based on a specific base.
 * This function interprets a given string as a number in the specified base
 * and converts it to an integer. The function handles both positive and
 * negative numbers, skipping leading whitespaces and optional signs.
 *
 * @param str the string to be converted
 * @param base the base to interpret the number in (e.g., 10 for decimal,
 * 16 for hexadecimal)
 * @return The converted integer. If the string is invalid or cointains
 * characters not allowed in the specified base, the result is undefined.
 * Returns 0 if the convertion fails.
*/
int		ft_atoi_base(char *str, int base);

/* @brief Counts the number of "words" in the given string, separeted by the
 * delimiter "c".
 * 
 * @param s the string to be used
 * @param c the delimiter character
 * @return The number of "words" in the string s.
*/
int		ft_word_count(char const *s, char c);
#endif
