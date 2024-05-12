#include"../header/push_swap.h"

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->nxt != NULL)
		stack = stack->nxt;
	return (stack);
}