/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:38:01 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/24 14:35:27 by sohamdan         ###   ########.fr       */
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

int	read_operations(t_list **stack_a, t_list **stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (!follow_operations(op, stack_a, stack_b))
			return (ft_putstr_fd("Error\n", 2), free(op), 0);
		free(op);
		op = get_next_line(0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 2 && !av[1][0])
		return (ft_printf("Error\n"), 1);
	if (ac < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (!store_and_check(ac, av, &stack_a))
		return (-1);
	if (!read_operations(&stack_a, &stack_b))
		return (-1);
	if (is_it_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&stack_a);
	return (0);
}
