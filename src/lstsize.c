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
