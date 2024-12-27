NAME		= libft.a
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -rf

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include

INCLUDE		= -I ${INC_DIR}/

BOOLEAN_DIR	= ${SRC_DIR}/boolean
IO_DIR		= ${SRC_DIR}/io
LIST_DIR	= ${SRC_DIR}/list
MEM_DIR		= ${SRC_DIR}/mem
STRING_DIR	= ${SRC_DIR}/string
GNL_DIR		= ${SRC_DIR}/get_next_line
FT_PRINTF_DIR	= ${SRC_DIR}/ft_printf

SRCS		= ${BOOLEAN_DIR}/ft_isalnum.c \
		  ${BOOLEAN_DIR}/ft_isalpha.c \
		  ${BOOLEAN_DIR}/ft_isascii.c \
		  ${BOOLEAN_DIR}/ft_isdigit.c \
		  ${BOOLEAN_DIR}/ft_isprint.c \
		  ${IO_DIR}/ft_putchar_fd.c \
		  ${IO_DIR}/ft_putendl_fd.c \
		  ${IO_DIR}/ft_putnbr_fd.c \
		  ${IO_DIR}/ft_putstr_fd.c \
		  ${LIST_DIR}/ft_lstadd_back.c \
		  ${LIST_DIR}/ft_lstadd_front.c \
		  ${LIST_DIR}/ft_lstclear.c \
		  ${LIST_DIR}/ft_lstdelone.c \
		  ${LIST_DIR}/ft_lstiter.c \
		  ${LIST_DIR}/ft_lstlast.c \
		  ${LIST_DIR}/ft_lstmap.c \
		  ${LIST_DIR}/ft_lstnew.c \
		  ${LIST_DIR}/ft_lstsize.c \
		  ${MEM_DIR}/ft_bzero.c \
		  ${MEM_DIR}/ft_calloc.c \
		  ${MEM_DIR}/ft_memchr.c \
		  ${MEM_DIR}/ft_memcmp.c \
		  ${MEM_DIR}/ft_memcpy.c \
		  ${MEM_DIR}/ft_memmove.c \
		  ${MEM_DIR}/ft_memset.c \
		  ${STRING_DIR}/ft_atoi.c \
		  ${STRING_DIR}/ft_itoa.c \
		  ${STRING_DIR}/ft_split.c \
		  ${STRING_DIR}/ft_strchr.c \
		  ${STRING_DIR}/ft_strdup.c \
		  ${STRING_DIR}/ft_striteri.c \
		  ${STRING_DIR}/ft_strjoin.c \
		  ${STRING_DIR}/ft_strlcat.c \
		  ${STRING_DIR}/ft_strlcpy.c \
		  ${STRING_DIR}/ft_strlen.c \
		  ${STRING_DIR}/ft_strmapi.c \
		  ${STRING_DIR}/ft_strncmp.c \
		  ${STRING_DIR}/ft_strnstr.c \
		  ${STRING_DIR}/ft_strrchr.c \
		  ${STRING_DIR}/ft_strtrim.c \
		  ${STRING_DIR}/ft_substr.c \
		  ${STRING_DIR}/ft_tolower.c \
		  ${STRING_DIR}/ft_toupper.c \
		  ${GNL_DIR}/get_next_line.c \
		  ${GNL_DIR}/get_next_line_utils.c \
		  ${FT_PRINTF_DIR}/ft_printf.c \
		  ${FT_PRINTF_DIR}/ft_printf_buffer.c \
		  ${FT_PRINTF_DIR}/ft_printf_char.c \
		  ${FT_PRINTF_DIR}/ft_printf_int.c \
		  ${FT_PRINTF_DIR}/ft_printf_parser.c \
		  ${FT_PRINTF_DIR}/ft_printf_str.c \
		  ${FT_PRINTF_DIR}/ft_printf_utils.c \

OBJS		= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS} 

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
			@mkdir -p ${@D}
			${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
			${RM} ${OBJ_DIR}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
