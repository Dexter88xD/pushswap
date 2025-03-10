/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:16:35 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/07 15:09:50 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	free_node(char **nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
		free(nbr[i++]);
	free(nbr);
}

int	store_numbers(int ac, char **av, t_list **stack_a)
{
	char	**nbr;
	t_list	*new_node;

	int (i), numb, temp;
	numb = 1;
	while (numb < ac)
	{
		i = 0;
		nbr = ft_split(av[numb], ' ');
		if (!*nbr)
			return (free_node(nbr), ft_lstclear(stack_a), 0);
		while (nbr[i])
		{
			if (check_numbers(i, nbr) == 0)
				return (free_node(nbr), ft_lstclear(stack_a), 0);
			temp = ft_atoi(nbr[i]);
			new_node = ft_lstnew(temp);
			if (!new_node)
				return (free_node(nbr), ft_lstclear(stack_a), 0);
			ft_lstadd_back(stack_a, new_node);
			i++;
		}
		((free_node(nbr)), numb++);
	}
	return (1);
}

int	store_and_check(int ac, char **av, t_list **stack_a)
{
	if (store_numbers(ac, av, stack_a) == 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (check_duplicates(*stack_a) == 0)
		return (ft_putstr_fd("Error\n", 2), ft_lstclear(stack_a), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (store_and_check(ac, av, &stack_a) == 0)
		return (-1);
	if (!is_it_sorted(stack_a))
		sorting(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
