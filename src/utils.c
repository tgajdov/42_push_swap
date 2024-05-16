/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:09:16 by tgajdov           #+#    #+#             */
/*   Updated: 2024/05/12 16:09:34 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->cheapest == true)
		stack = stack->nxt;
	return (stack);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
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

int	lstsize(t_stack_node *lst)
{
	int				i;
	t_stack_node	*copie_lst;

	copie_lst = lst;
	i = 0;
	while (copie_lst)
	{
		copie_lst = copie_lst->nxt;
		i++;
	}
	return (i);
}
