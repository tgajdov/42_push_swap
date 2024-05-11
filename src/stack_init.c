#include"../header/push_swap.h"

void	stack_init(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors(a); */
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_depulicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}