#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "../lib/includes/libft.h"

typedef struct s_node
{
	int				val;
	int				ind;
	struct s_node	*nxt;
}				t_node;

void	ft_print_list(t_node *head);

void	ft_free_array(char **array);

#endif