#include "lib/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (1);
	stack_a = parser(argc, argv);
	if (argv[1][0] == '\0' || !stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_reverse_rotate(&stack_a);
	printf("%d ; %d ; %d\n", stack_a->value, stack_a->next->value, stack_a->next->next->value);
	clear_stack(stack_a, stack_b);
	return (0);
}
