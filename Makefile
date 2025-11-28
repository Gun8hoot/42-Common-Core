NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I. -c -g3

PRINTF_PATH	=	external/printf
LIBFT_PATH	=	external/libft
LIB_PATH	=	lib


SRC			=	$(SRC_DIR)/check.c\
				$(SRC_DIR)/command_both.c\
				$(SRC_DIR)/command_core.c\
				$(SRC_DIR)/linked_list.c\
				$(SRC_DIR)/parser.c\
				$(SRC_DIR)/push_swap.c\
				$(SRC_DIR)/small_mid_sort.c\
				$(SRC_DIR)/chunk_sort.c\
				$(SRC_DIR)/sort.c\
				$(SRC_DIR)/finder.c\
				$(SRC_DIR)/.debug.c

SRC_DIR		=	src

OBJ			= $(SRC:%.c=%.o)

all:	printf libft $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $@ lib/*.a

libft:
	make -C $(LIBFT_PATH)
	mv $(LIBFT_PATH)/libft.a $(LIB_PATH)

printf:
	make -C $(PRINTF_PATH)
	mv $(PRINTF_PATH)/libftprintf.a $(LIB_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	rm -f src/*.o

fclean:	clean
	rm -f lib/*.a
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re