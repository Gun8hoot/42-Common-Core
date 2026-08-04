NAME		=	ex00

COMPILER	=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -I. -c

ifdef DEBUG
FLAGS		+= -DDEBUG -g3
endif

SOURCES		=	$(wildcard *.cpp */*.cpp)
OBJECTS		=	file.o

all: $(NAME)

%.cpp: %.o
	@printf "\x1b[0;32m[+] Compiling %s\x1b[0m\n" $@
	$(COMPILER) $(FLAGS) $@ -o $<

$(NAME):
	@printf "\x1b[0;32m[+] Linking %s\x1b[0m\n" $@
	@$(COMPILER) $< -o $@

clean:
	@printf "\x1b[0;31m[+] Removing %s\x1b[0m\n" $(NAME)
	@rm -f $(NAME)

fclean: clean
	@printf "\x1b[0;31m[+] Removing %s\x1b[0m\n" $(OBJECTS)
	@rm -f $(OBJECTS)

re: fclean $(NAME)
