/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:47:48 by tgajdov           #+#    #+#             */
/*   Updated: 2024/05/13 19:47:49 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/push_swap.h"

static void	add_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->nxt = NULL;
	node->val = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->nxt = node;
		node->prev = last_node;
	}
}

void	stack_init(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors(a, 10);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, 11);
		if (error_duplicate(*a, (int)n))
			free_errors(a, 12);
		add_node(a, (int)n);
		i++;
	}
}
