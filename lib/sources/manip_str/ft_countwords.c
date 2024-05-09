#include "../../includes/libft.h"

int ft_countwords(char **tab)
{
    int i;

    i = 0;
    while(tab[i])
        i++;
    return(i);
}