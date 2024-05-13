/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:47:38 by tgajdov           #+#    #+#             */
/*   Updated: 2024/05/13 19:47:40 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/push_swap.h"

t_stack_node	*find_max(t_stack_node *stack)
{
	long			biggest;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack->nxt != NULL)
	{
		if (biggest < stack->val)
		{
			biggest = stack->val;
			max_node = stack;
		}
		stack = stack->nxt;
	}
	return (max_node);
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
