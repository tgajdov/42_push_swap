#include<./header/push_swap.h>

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	if(ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	/*Suite*/
	ft_free_array(av);
}