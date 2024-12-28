NAME		= fdf
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= -rm -rf

SRC_DIR		= src/
OBJ_DIR		= obj/
INC_DIR		= include/
LIBFT_DIR	= lib/libft/
LIBFT_LIB	= ${LIBFT_DIR}libft.a
MLX_DIR		= lib/mlx/
MLX_LIB		= ${MLX_DIR}libmlx_Linux.a


SRCS		= ${SRC_DIR}main.c \
		  ${SRC_DIR}map_parser.c \
		  ${SRC_DIR}map_utils.c \
		  ${SRC_DIR}errors.c \

OBJS		= ${SRCS:${SRC_DIR}%.c=${OBJ_DIR}%.o}

all:		${NAME}

${NAME}:	${OBJS} ${LIBFT_LIB} ${MLX_LIB}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} -I ${INC_DIR} -lm -lXext -lX11 -o ${NAME}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
			@mkdir -p ${OBJ_DIR}
			${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_DIR} -I ${MLX_DIR} -c $< -o $@

${LIBFT_LIB}:
			@echo "Building libft..."
			make -C ${LIBFT_DIR}

${MLX_LIB}:
			@echo "Building mlx..."
			make -C ${MLX_DIR}

clean:			
			@echo "Cleaning object files..."
			${RM} ${OBJ_DIR}
			@echo "Cleaning libft and mlx objects..."
			make clean -C ${LIBFT_DIR}
			make clean -C ${MLX_DIR}

fclean:		clean
			@echo "Removing binary and libraries..."
			${RM} ${NAME}
			make fclean -C ${LIBFT_DIR}
			${RM} ${MLX_LIB}

re:		fclean all

.PHONY:		all clean fclean re
