#include"../header/push_swap.h"

void	ft_print_list(t_stack_node *head)
{
	t_stack_node *current;
	int i;

	i = 0;
	current = head;
	while(current != NULL)
	{
		ft_printf("Value of node[%d]is :%d\n", i, current->val);
		current = current->nxt;
		i++;
	}
}