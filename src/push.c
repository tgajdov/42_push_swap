#include"../header/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	return ;
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b); 
	if (!print) 
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}