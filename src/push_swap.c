#include "lib/push_swap.h"

int main(int argc, char **argv)
{
	t_stacks *stack_a;
	t_stacks *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	if (argv2lst(stack_a, argc, argv) == 1)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
}
