#include"../header/push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->nxt)
	{
		if (stack->val > stack->nxt->val)
			return (false);
		stack = stack->nxt;
	}
	return (true);
}