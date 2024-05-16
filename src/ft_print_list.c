/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:46:30 by tgajdov           #+#    #+#             */
/*   Updated: 2024/05/13 19:46:31 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/push_swap.h"

void	ft_print_list(t_stack_node *head, char *name)
{
	t_stack_node	*current;
	int				i;

	i = 0;
	current = head;
	ft_printf("The stack : %s\n", name);
	while (current != NULL)
	{
		ft_print_node(current);
		//ft_printf("Index of node[%d]is :%d\n", current->val, current->ind);
		current = current->nxt;
		i++;
	}
	ft_printf("\n");
}

void	ft_print_node(t_stack_node *head)
{
	ft_printf("Value of node :[%d]\n", head->val);
	// ft_printf("Index[%d]\n", head->ind);
	ft_printf("Push_cost :[%d]\n", head->push_cost);
	if (head->target_node)
		ft_printf("Value of target node[%d]\n", head->target_node->val);
	// if (head->nxt)
	// 	ft_printf("Value of nxt node[%d]\n", head->nxt->val);
	// if (head->prev)
	// 	ft_printf("Value of prev node[%d]\n", head->prev->val);
	ft_printf("\n");
}