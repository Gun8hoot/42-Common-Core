NAME		=	so_long
CFLAGS		=	-Wall -Wextra -Werror -I. -g3

SRC			=	$(SRC_DIR)/maps/maps.c\
				$(SRC_DIR)/maps/maps_verif.c\
				$(SRC_DIR)/render/render.c\
				$(SRC_DIR)/safety_free.c\
				$(SRC_DIR)/so_long.c
GNL			=	external/gnl/get_next_line.c\
				external/gnl/get_next_line_utils.c
OBJS		=	$(SRC:%.c=%.o)

SRC_DIR		=	src
LIB_DIR		=	lib

%.c: %.o
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	make -C external/minilibx-linux
	make -C external/printf
	mv external/printf/*.a lib
	make -C external/libft
	mv external/libft/*.a lib
	$(CC) $^ -o $@ lib/*.a $(GNL)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f lib/*.a
	rm -f $(NAME)