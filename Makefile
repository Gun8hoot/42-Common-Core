#	--- DEFINE VARS ---
NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I. -O1
SRCS		=	$(SRC_DIR)maps_verif.c\
				$(SRC_DIR)maps.c\
				$(SRC_DIR)safety_free.c\
				$(SRC_DIR)so_long.c\
				$(GNL_PATH)
LIB			=	$(LIB_DIR)/libft.a\
				$(LIB_DIR)/libprintf.a\
				$(LIB_DIR)/libmlx.a\
				$(LIB_DIR)/libmlx_Linux.a
OBJ			=	$(SRC:%.c=%.o)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $<

#		--- PATH ---
SRC_DIR			=	src/
LIB_DIR			=	lib/
OBJ_DIR			=	obj/

PRINTF_PATH		=	external/printf/
LIBFT_PATH		=	external/libft/
MINILIBX_PATH	=	external/minilibx-linux/
GNL_PATH		=	external/get_next_line/


# -------------------------------------

#	--- MAKEFILE BASIC RULES ---
all: $(NAME)

$(NAME): external

clean:
	@echo "\e[0;31mCleaning all .o files\e[0m"
	make -C $(PRINTF_PATH) clean
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean


fclean: clean
	@echo "\e[0;31mCleaning all compilation files\e[0m"
	rm -f lib/*.a
	rm -f $(EXEC_NAME)

re: fclean all
	@echo "\e[0;32mRecreate everything\e[0m"


#	--- EXTERNAL COMPILATION RULES ---
external:
	@echo "Compiling minilibx"
	make -C $(MINILIBX_PATH)
	@mv $(MINILIBX_PATH)*.a lib/
	@echo "Compiling printf"
	make -C $(PRINTF_PATH)
	@mv $(PRINTF_PATH)*.a lib/
	@echo "Compiling libft"
	make -C $(LIBFT_PATH)
	@mv $(LIBFT_PATH)*.a lib/

#	--- COMPILATION RULES ---
$(NAME): external
	$(CC) $(OBJ) -o $@

.PHONY: clean fclean re $(NAME)