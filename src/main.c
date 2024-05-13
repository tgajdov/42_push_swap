/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:46:59 by tgajdov           #+#    #+#             */
/*   Updated: 2024/05/13 19:47:01 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/push_swap.h"

int	ft_check_ber(char *game)
{
	char	*ext_needed;
	char	*ext_file;

	ext_needed = ".txt";
	if (!(ext_file = ft_strrchr(game, '.')))
		return (0);
	if (!ft_strcmp(ext_file, ext_needed) && ft_strlen(ext_file) == 4)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				fd;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (1);
	else if (ac == 2)
	{
		if(ft_check_ber(av[1])) // a suprimer pour le rendu!!!
		{
			fd = open(av[1], O_RDONLY);
			av[1] = get_next_line(fd);
		}
		av = ft_split(av[1], ' ');
		stack_init(&a, av); //tester les leaks si av est creer par ft_split
		ft_free_array(av);
	}
	else
		stack_init(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (lstsize(a) == 2)
			sa(&a, false);
		else if (lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	exit (0);
}
