NAME		= fdf
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -rf

SRC_DIR		= ./
OBJ_DIR		= obj/
INCLUDE		= -I . -lm -lXext -lX11
LIBFT_DIR	= lib/libft/
LIBFT_LIB	= ${LIBFT_DIR}libft.a
MLX_DIR		= lib/minilibx-linux/
MLX_LIB		= ${MLX_DIR}libmlx_Linux.a
TEST_FILE	?= maps/teste1.fdf

SRCS		= $(SRC_DIR)main.c \
		  ${SRC_DIR}init_structs.c \
		  ${SRC_DIR}init_utils.c \
		  ${SRC_DIR}read.c \
		  ${SRC_DIR}errors.c \
		  ${SRC_DIR}render.c \
		  ${SRC_DIR}draw.c \
		  ${SRC_DIR}close.c \
		  ${SRC_DIR}utils.c \
		  ${SRC_DIR}color.c \
		  ${SRC_DIR}rotate.c \
		  ${SRC_DIR}project.c \
		  ${SRC_DIR}transform.c \
		  ${SRC_DIR}key_handle.c \
		  ${SRC_DIR}menu.c \

OBJS		= ${SRCS:${SRC_DIR}%.c=${OBJ_DIR}%.o}

all:		${OBJ_DIR} ${NAME}

${NAME}:	${OBJS} ${LIBFT_LIB} ${MLX_LIB}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} ${INCLUDE} -o ${NAME}

${OBJ_DIR}:
			@mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
			@mkdir -p ${OBJ_DIR}
			${CC} ${CFLAGS} -I . -I ${LIBFT_DIR} -I ${MLX_DIR} -c $< -o $@

${LIBFT_LIB}:
			@echo "Building libft..."
			make -C ${LIBFT_DIR}

${MLX_LIB}:
			@echo "Building mlx..."
			make -C ${MLX_DIR}

leakfull:
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} ${TEST_FILE}

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

# Profiling target to run the program and then analyze with gprof
gprof:		${OBJ_DIR} ${NAME}
			@echo "Running the program with gprof profiling..."
			./${NAME} ${TEST_FILE}
			@echo "Generating gprof report..."
			gprof ${NAME} gmon.out > gprof_report.txt
			@echo "Gprof report saved as gprof_report.txt"

.PHONY:		all clean fclean re
