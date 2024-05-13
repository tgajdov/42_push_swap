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

t_stack_node	*find_min(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack->nxt != NULL)
	{
		if (smallest > stack->val)
		{
			smallest = stack->val;
			min_node = stack;
		}
		stack = stack->nxt;
	}
	return (min_node);
}

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = lstsize(stack) / 2;
	while(stack)
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

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->val > b->val && current_a->val < best_match_index)
			{
				best_match_index = current_a->val;
				target_node = current_a;
			}
			current_a = current_a->nxt;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->nxt;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = lstsize(a);
	len_b = lstsize(b);
	while (b)
	{
		b->push_cost = b->ind;
		if (!b->above_med)
			b->push_cost = len_b - b->ind;
		if (b->target_node->above_med)
			b->push_cost += b->target_node->ind;
		else
			b->push_cost += len_a - b->target_node->ind;
		b = b->nxt;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_price(a, b);
	set_cheapest(a);
	return ;
}
