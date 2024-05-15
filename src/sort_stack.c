/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:47:30 by tgajdov           #+#    #+#             */
/*   Updated: 2024/05/13 19:47:32 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/push_swap.h"

// static	int		i = 0;
//printf("Passage :%d\nMy NODE[%d]\nHis value :%d\nHis push_cost:%d\nHe's above the median :%d\nHe's the cheapest :%d\n\n", i, cheapest_node->ind, cheapest_node->val, cheapest_node->push_cost, cheapest_node->above_med, cheapest_node->cheapest);

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);// c'est ici quejai un probleme a analzser je ne comprend pas pq
	if (cheapest_node->above_med && cheapest_node->target_node->above_med)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_med
		&& !cheapest_node->target_node->above_med)
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->val != find_min(*a)->val)
	{
		if (find_min(*a)->above_med)
		{
			ft_print_list(*a);
			ra(a, false);
			printf("ca printf ici\n");
		}
		else
		{
			rra(a, false);
			printf("ca printf la\n");
		}
	}
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->nxt == biggest_node)
		rra(a, false);
	if ((*a)->val > (*a)->nxt->val)
		sa(a, false);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = lstsize(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
	ft_print_list(*a);
}

/* Probleme a partir de  10 imputs, je pense qu'il set trop de cheapest mais je suis pas sur */