# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbardet- <lbardet-@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 05:37:45 by lbardet-          #+#    #+#              #
#    Updated: 2025/07/27 22:22:48 by lbardet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC        =    gcc
CFLAGS    =    -Wall -Wextra -Werror
NAME    =    rush-02
SRC_DIR    =    src
OBJ_DIR    =    obj

SRC        =    $(wildcard $(SRC_DIR)/*.c)
OBJ        =    $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)

.PHONY: all clean fclean