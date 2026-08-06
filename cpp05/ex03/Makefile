NAME		=	ex02

COMPILER	=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -I. -c -O2

ifdef DEBUG
FLAGS		+= -DDEBUG -g3
endif

OBJECT_DIR	=	.objects

SOURCES		=	$(wildcard *.cpp */*.cpp)
OBJECTS		=	$(patsubst %.cpp,$(OBJECT_DIR)/%.o,$(SOURCES))

all: $(NAME)

$(OBJECT_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "\x1b[0;32m[+] Compiling %s\x1b[0m\n" $@
	@$(COMPILER) $(FLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@printf "\x1b[0;32m[+] Linking %s\x1b[0m\n" $@
	@$(COMPILER) $^ -o $@

clean:
	@printf "\x1b[0;31m[+] Removing %s\x1b[0m\n" $(NAME)
	@rm -f $(OBJECTS)

fclean: clean
	@printf "\x1b[0;31m[+] Removing %s\x1b[0m\n" $(OBJECTS)
	@rm -f $(NAME)

re: fclean $(NAME)
