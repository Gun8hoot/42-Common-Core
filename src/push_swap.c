#include "lib/push_swap.h"

int main(int argc, char **argv)
{
	t_stacks *stack_a;
	if (argc < 2)
		return (EXIT_FAILURE);
	if (argv2lst(stack_a, argc, argv) == 1)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
}