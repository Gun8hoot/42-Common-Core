#include "lib/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (!parser(argc, argv) || argv[1][0] == '\0')
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
