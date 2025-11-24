#include "lib/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	ft_memset(stack_a, 0, sizeof(stack_a));
	stack_b = NULL;
	if (argc < 2)
		return (1);
	stack_a = parser(argc, argv);
	if (argv[1][0] == '\0' || !stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_sa(stack_a);
	printf("%d\n", stack_a->value);
	clear_stack(stack_a, stack_b);
	return (0);
}
