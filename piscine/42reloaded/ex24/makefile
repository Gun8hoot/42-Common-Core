NAME := MAKEFILE+LIB
LIBNAME := libft.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror

OBJS_DIR := ./objs
SRCS_DIR := ./srcs
LIB_DIR  := ./includes
#OBJS := $(OBJS_DIR)/ft_putchar.o $(OBJS_DIR)/ft_putstr.o $(OBJS_DIR)/ft_strcmp.o $(OBJS_DIR)/ft_strlen.o $(OBJS_DIR)/ft_swap.o
OBJS := $(SRCS:%.c=%.o)
SRCS := $(OBJS_SRC)/ft_putchar.c $(OBJS_SRCS)/ft_putstr.c $(OBJS_SRCS)/ft_strcmp.c $(OBJS_SRC)/ft_strlen.c $(OBJS_SRC)/ft_swap.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)
#	gcc -I./includes -L. -lft ./file.c -o NAME 

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -c -o $@ $<
	
.PHONY: clean fclean re

clean:
	rm -f ./objs/* ./*.a

re: $(fclean)
	$(NAME)

fclean: $(clean)
	rm -f $(NAME)
