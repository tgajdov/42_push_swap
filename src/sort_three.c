#include"../header/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->nxt == biggest_node)
		rra(a, false);
	if ((*a)->val > (*a)->nxt->val)
		sa(a, false);
}