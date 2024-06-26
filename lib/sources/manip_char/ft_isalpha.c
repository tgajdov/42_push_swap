/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:52:41 by tgajdov           #+#    #+#             */
/*   Updated: 2023/10/30 15:48:37 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isalpha(int n)
{
	if (((n >= 'A') && (n <= 'Z')) || ((n >= 'a') && (n <= 'z')))
		return (1);
	else
		return (0);
}
