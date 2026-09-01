NAME		=	so_long
CFLAGS		=	-Wall -Wextra -Werror -I. -g3 -O2 -c
MLX_FLAG	=	-L$(MLX_DIR) -lm -lXext -lX11

SRC			=	$(SRC_DIR)/maps/maps.c\
				$(SRC_DIR)/maps/maps_verif.c\
				$(SRC_DIR)/maps/flood_fill.c\
				$(SRC_DIR)/render/render.c\
				$(SRC_DIR)/logic/logic.c\
				$(SRC_DIR)/logic/event.c\
				$(SRC_DIR)/safety_free.c\
				$(SRC_DIR)/so_long.c\
				$(SRC_DIR)/utils.c\
				$(SRC_DIR)/.debug.c\
				external/gnl/get_next_line.c\
				external/gnl/get_next_line_utils.c
OBJS		=	$(SRC:%.c=%.o)

SRC_DIR		=	src
LIB_DIR		=	lib
MLX_DIR		=	external/minilibx-linux

all: $(NAME)

%.c: %.o
	$(CC) $(CFLAGS) $< -o $@

PRINTF:
	make -C external/printf
	mv external/printf/*.a lib/

LIBFT:
	make -C external/libft
	mv external/libft/*.a lib/

MINILIBX:
	rm -f minilibx-linux.tgz
	wget https://cdn.intra.42.fr/document/document/52025/minilibx-linux.tgz
	tar xvfz minilibx-linux.tgz -C external
	make -C external/minilibx-linux
	mv external/minilibx-linux/*.a lib/

$(NAME): MINILIBX PRINTF LIBFT $(OBJS)
	$(CC) $(GNL) $(OBJS) -o $@ lib/*.a $(MLX_FLAG)

clean:
	make -C external/printf clean
	@if [ -d external/minilibx-linux ]; then make -C external/minilibx-linux clean; fi
	make -C external/libft clean
	rm -f $(OBJS)
	rm -f minilibx-linux.tgz

fclean: clean
	rm -rf external/minilibx-linux
	rm -f lib/*.a
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all