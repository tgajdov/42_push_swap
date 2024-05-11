#include"../../includes/libft.h"

void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while(array[i])
		ft_printf("%s\n", array[i++]);
}