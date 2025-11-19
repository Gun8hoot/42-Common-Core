# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 07:38:08 by nclavel           #+#    #+#              #
#    Updated: 2025/11/04 10:04:16 by nclavel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
#	VARIABLES	#
#################

NAME	=	libftprintf.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I.

SRC		=	./src/ft_printf.c\
			./src/format1.c\
			./src/format2.c

LIB_DIR	=	lib/

OBJS	=	$(SRC:%.c=%.o)

##############
#	TARGET   #
##############

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