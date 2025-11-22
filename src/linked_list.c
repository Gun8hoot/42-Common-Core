#include "lib/push_swap.h"

t_stack	*stack_new_node(int nb)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->value = nb;
	list->next = NULL;
	return (list);
}

t_stack	*stack_list_last(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
	
}

t_stack	*stack_add_back(t_stack **head, t_stack *node)
{
	t_stack	*last;

	if (!*head)
	{
		*head = node;
		return (*head);
	}
	last = stack_list_last(*head);
	last->next = node;
	return (*head);
}

t_stack	*linked_list(t_stack **head, int number)
{
	t_stack	*node;

	node = stack_new_node(number);
	if (!node)
		return (NULL);
	stack_add_back(head, node);
	return (*head);
}
