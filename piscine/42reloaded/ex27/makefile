#	╔═══════════════╗
#	║	VARIABLE    ║
#	╚═══════════════╝ 

NAME := display_file
CC := gcc
CFLAGS := -I./lib
OBJS := $(OBJS)/diplay.o $(OBJS)/check.o $(OBJS)/main.o
SRC := src/check.c src/display.c src/main.c
SRCS := $(addprefix $(SRCS_DIR) )

#	╔═══════════════╗
#	║	   DIR      ║
#	╚═══════════════╝ 

SRCS_DIR := src/
OBJS_DIR := obj/

#	╔═══════════════╗
#	║	FUNCTION    ║
#	╚═══════════════╝ 

all: $(NAME)

$(NAME):
	mkdir -p ./objs
	$(CC) $(OBJS)  -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	rm -f ./objs/*

re: $(fclean)
	$(NAME)

fclean: $(clean)
	rm -f $(NAME)
