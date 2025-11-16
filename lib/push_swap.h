#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "external/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>

typedef struct s_stacks
{
	struct s_stacks *previous;
	struct s_stacks *next;
	int	value;
} t_stacks;

int	argv2lst(t_stacks *stack_a, int ac, char **av);
#endif