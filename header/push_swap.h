/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:27:33 by tgajdov           #+#    #+#             */
/*   Updated: 2024/05/11 16:27:35 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include "../lib/includes/libft.h"

typedef struct s_stck_node
{
	int				val;
	int				ind;
	int				push_cost;
	bool			above_med;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*nxt;
	struct s_node	*prev;
}	t_stack_node;

/* -------◊	Handle errors		◊------- */
/* -------◊	Stack initiation	◊------- */
/* -------◊	Nodes initiation	◊------- */
/* -------◊	Stack utils			◊------- */
/* -------◊	Commands			◊------- */
/* -------◊	Algo				◊------- */

void	ft_print_list(t_stack_node *head);
void	ft_free_array(char **array);
void	stack_init(t_stack_node **a, char **av);


#endif
