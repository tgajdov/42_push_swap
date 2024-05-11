#include<../header/push_swap.h>

void	ft_print_list(t_stack_node *head)
{
	t_stack_node *current;

	current = head;
	while(current != NULL)
	{
		ft_printf("%d\n", current->val);
		current = current->nxt;
	}
}