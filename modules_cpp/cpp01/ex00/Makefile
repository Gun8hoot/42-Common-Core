NAME = zombie

CPPC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -I.

SRCS = newZombie.cpp\
	   randomChump.cpp\
	   main.cpp\
	   class/Zombie.cpp

OBJS = $(SRCS:%.cpp=%.o)

all : $(NAME)


%.o : %.cpp 
	$(CPPC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	$(CPPC) $(OBJS) -o $@

clean :
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: re all clean fclean $(NAME)
