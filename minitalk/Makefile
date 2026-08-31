#	--- DEFINE VARS ---
NAME		=	minitalk
PRINTF_PATH =	external/printf/
LIBFT_PATH =	external/libft/
SRC_DIR		=	src/

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I. -O1 -g3

SRCS		=	$(SRC_DIR)client.c\
				$(SRC_DIR)server.c

LIB			=	lib/libft.a\
				lib/libprintf.a

EXEC_NAME	=	client\
				server


#	--- MAKEFILE BASIC RULES ---
all: $(NAME)

$(NAME): client server


clean:
	@echo "\e[0;31mCleaning all .o files\e[0m"
	make -C $(PRINTF_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	@echo "\e[0;31mCleaning all compilation files\e[0m"
	rm -f lib/*.a
	rm -f $(EXEC_NAME)

re: fclean all
	@echo "\e[0;32mHave recreate everything\e[0m"


#	--- EXTERNAL COMPILATION RULES ---
printf:
	@echo "\e[0;32mCompiling ft_printf\e[0m"
	@make -C $(PRINTF_PATH)
	mv $(PRINTF_PATH)libftprintf.a lib/libprintf.a

libft:
	@echo "\e[0;32mCompiling libft\e[0m"
	@make -C $(LIBFT_PATH)
	mv $(LIBFT_PATH)libft.a lib/libft.a


#	--- COMPILATION RULES ---
client: printf libft
	@echo "\e[0;32mCompiling minitalk client\e[0m"
	$(CC) $(CFLAGS) $(SRC_DIR)client.c -o $@ $(LIB)

server: printf libft
	@echo -e "\e[0;32mCompiling minitalk server\e[0m"
	$(CC) $(CFLAGS) $(SRC_DIR)server.c -o $@ $(LIB)


.PHONY: clean fclean re printf
