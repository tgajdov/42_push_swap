/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:48:03 by tgajdov           #+#    #+#             */
/*   Updated: 2024/05/13 19:48:04 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/push_swap.h"

static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->nxt)
		return ;
	*head = (*head)->nxt;
	(*head)->prev->prev = *head;
	(*head)->prev->nxt = (*head)->nxt;
	if ((*head)->nxt)
		(*head)->nxt->prev = (*head)->prev;
	(*head)->nxt = (*head)->prev;
	(*head)->prev = NULL;
	return ;
}

void	sa(t_stack_node	**a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
