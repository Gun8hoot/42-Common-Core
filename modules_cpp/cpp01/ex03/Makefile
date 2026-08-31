NAME = unnecessary_violence

CPPC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -I.

SRCS = main.cpp\
			 class/Weapon.cpp\
			 class/HumanA.cpp\
			 class/HumanB.cpp

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
