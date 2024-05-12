#include"../header/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	
	if (!*stack || !(*stack)->nxt)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->nxt = NULL;
	last_node->nxt = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->nxt->prev = last_node;
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}