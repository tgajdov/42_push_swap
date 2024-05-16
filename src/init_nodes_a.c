/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:46:37 by tgajdov           #+#    #+#             */
/*   Updated: 2024/05/13 19:46:38 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = lstsize(stack) / 2;
	while (stack)
	{
		stack->ind = i;
		if (i <= median)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->nxt;
		i++;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->val < a->val && current_b->val > best_match_index)
			{
				best_match_index = current_b->val;
				target_node = current_b;
			}
			current_b = current_b->nxt;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->nxt;
	}
}

void	set_price_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = lstsize(a);
	len_b = lstsize(b);
	while (a)
	{
		a->push_cost = a->ind;
		if (!(a->above_med))
			a->push_cost = len_a - (a->ind);
		if (a->target_node->above_med)
			a->push_cost += a->target_node->ind;
		else
			a->push_cost += len_b - (a->target_node->ind);
		//ft_print_node(a);
		a = a->nxt;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_val;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_val = LONG_MAX;
	while (stack)
	{
		stack->cheapest = false;
		if (stack->push_cost < cheapest_val)
		{
			cheapest_val = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->nxt;
	}
	// ft_printf("MY CHEAPEST NODE IS :");
	// ft_print_node(cheapest_node);
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	set_price_a(a, b);
	set_cheapest(a);
	return ;
}
