NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I. -c

PRINTF_PATH	=	external/printf
LIBFT_PATH	=	external/libft
LIB_PATH	=	lib


SRC			=	$(SRC_DIR)/parser.c\
				$(SRC_DIR)/check.c\
				$(SRC_DIR)/push_swap.c\
				$(SRC_DIR)/linked_list.c\
				$(SRC_DIR)/mouvement_1.c\
				$(SRC_DIR)/movement_2.c\
				$(SRC_DIR)/sorting.c

SRC_DIR		=	src

OBJ_DIR		=	obj

OBJ			= $(SRC:%.c=%.o)

all:	$(NAME)

%.o: %.o
	$(CC) $(CFLAGS) $< -o $@

$(NAME): libft printf $(OBJ)
	$(CC) $(OBJ) -o $@

libft:
	make -C $(LIBFT_PATH)
	mv $(LIBFT_PATH)/libft.a $(LIB_PATH)

printf:
	make -C $(PRINTF_PATH)
	mv $(PRINTF_PATH)/libftprintf.a $(LIB_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	rm -f obj/*

fclean:	clean
	rm -f lib/*.a
	rm $(NAME)
