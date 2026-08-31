NAME = animals

CPPC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -I.

SRCS =	main.cpp\
		Cat.cpp\
		Dog.cpp\
		wrongAnimal.cpp\
		wrongCat.cpp\
		Animal.cpp

OBJS = $(SRCS:%.cpp=%.o)

all : $(NAME)

%.o : %.cpp
	$(CPPC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPPC) $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: re all clean fclean
