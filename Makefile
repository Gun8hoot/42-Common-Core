NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I.

LIBFT_PATH	=	external/libft
LIB_PATH	=	lib

SRC			=	$(SRC_DIR)/parser.c\
				$(SRC_DIR)/push_swap.c\
				$(SRC_DIR)/push_swap.c\
				$(SRC_DIR)/push_swap.c\
SRC_DIR		=	src

OBJ_DIR		=	obj

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@
libft:
	make -C $(LIBFT_PATH)
	mv $(LIBFT_PATH)/libft.a $(LIB_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f obj/*

fclean:	clean
	rm -f lib/*.a
	rm $(NAME)
