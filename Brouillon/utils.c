#include<../header/push_swap.h>

void	ft_print_list(t_node *head)
{
	t_node *current;

	current = head;
	while(current != NULL)
	{
		ft_printf("%d\n", current->val);
		current = current->nxt;
	}
}