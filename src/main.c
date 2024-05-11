#include"../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
	 	stack_init(&a, av);
	}
	else
		stack_init(&a, av + 1);
	ft_print_list(&a);
/* 	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a)  == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a); */
	return (0);
}