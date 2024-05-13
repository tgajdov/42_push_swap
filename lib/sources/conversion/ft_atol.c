#include "../../includes/libft.h"

long	ft_atol(const char *str)
{
	int		i;
	int		pair;
	long	nb;

	i = 0;
	nb = 0;
	pair = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pair *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * pair);
}