NAME	=	libftprintf.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I.

SRC		=	./src/ft_printf.c\
			./src/cspdiuxX%_1.c\
			./src/cspdiuxX%_2.c

LIB_DIR	=	lib/

OBJS	=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re