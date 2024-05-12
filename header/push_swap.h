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

typedef struct s_stack_node
{
	int					val;
	int					ind;
	int					push_cost;
	bool				above_med;
	bool				cheapest;

	struct s_stack_node	*target_node;
	struct s_stack_node	*nxt;
	struct s_stack_node	*prev;
}	t_stack_node;

/* -------◊	Handle errors		◊------- */
/* -------◊	Stack initiation	◊------- */
void			stack_init(t_stack_node **a, char **av);

/* -------◊	Nodes initiation	◊------- */

/* -------◊	Stack utils			◊------- */
t_stack_node	*find_last_node(t_stack_node *stack);
int				lstsize(t_stack_node *lst);

/* -------◊	Commands			◊------- */
static void		push(t_stack_node **dst, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
static void		swap(t_stack_node **head);
void			sa(t_stack_node	**a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
static void		rotate(t_stack_node **stack);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
static void		rev_rotate(t_stack_node **stack);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

/* -------◊	Algo				◊------- */
bool			stack_sorted(t_stack_node *stack);
void			sort_three(t_stack_node **a);

/* -------◊	Rests				◊------- */
void			ft_print_list(t_stack_node *head);
void			ft_free_array(char **array);


#endif
