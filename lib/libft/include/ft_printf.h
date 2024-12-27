/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:35:09 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/26 03:35:16 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 4096
# define FLAGS "+- 0#"
# define NUMBERS "0123456789"
# define SPECIFIERS "cspdiuxX%"
# define LOW_HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"

typedef union t_union_int
{
	unsigned long	uint64;
	long			int64;
}	t_union_int;

typedef struct s_format
{
	int		plus;
	int		left_justified;
	int		space;
	int		zero_pad;
	int		hash;
	char	specifier;
	int		width_value;
	int		precision_value;
	char	buf_temp[64];
	int		nbr_len;
	int		upper_case;
	int		base;
	int		padding_spaces;
	int		padding_zeros;
	int		signed_value;
	int		is_negative;
	int		is_converted;
}	t_format;

typedef struct s_data
{
	const char	*s;
	va_list		ap;
	int			chars_written;
	char		*buf;
	int			buffer_index;
	t_format	format;
}	t_data;

// PROTOTYPES

int		ft_printf(const char *format, ...);

// utils
int		in(const char *s, char c);
int		s_len(const char *s);

// parser
int		parse_format(t_data *data);

// buffer
void	write_buf(t_data *data, char c);
void	flush_buf(t_data *data);
void	putchar_buf_n(char c, int n, t_data *data);
void	putstr_buf_n(char *s, int precision, t_data *data);
void	itoa_buf(t_data *data, t_union_int int_values);

// print
void	printf_char(t_data *data, int c);
void	printf_str(t_data *data, char *s);
void	printf_int(t_data *data, t_union_int int_values);

#endif 
