/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:38:01 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/24 00:54:59 by sohamdan         ###   ########.fr       */
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
		free_node(nbr);
		numb++;
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

int	read_instructions(char **instructions)
{
	int	i;

	i = 0;
	instructions[i] = get_next_line(0);
	while (instructions[i])
	{
		i++;
		instructions[i] = get_next_line(0);
	}
	instructions[i] = NULL;
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**instructions;
	int		i;

	i = 0;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (ft_printf("Error\n"), 1);
	stack_a = NULL;
	stack_b = NULL;
	if (store_and_check(ac, av, &stack_a) == 0)
		return (-1);
	instructions = malloc(10000 * sizeof(char *));
	if (!instructions)
		return (-1);
	read_instructions(instructions);
	// function to check if there is something other than the operations
	while (instructions[i])
	{
		// ft_printf("Operation number %d: %s", i + 1, instructions[i]);
		if (ft_strncmp(instructions[i], "ra", ft_strlen(instructions[i])))
			rotate_a(&stack_a, 1);
		else if (ft_strncmp(instructions[i], "rb", ft_strlen(instructions[i])))
			rotate_b(&stack_b, 1);
		else if (ft_strncmp(instructions[i], "rr", ft_strlen(instructions[i])))
			rotate_a_b(&stack_a, &stack_b);
		else if (ft_strncmp(instructions[i], "rra", ft_strlen(instructions[i])))
			reverse_rotate_a(&stack_a, 1);
		else if (ft_strncmp(instructions[i], "rrb", ft_strlen(instructions[i])))
			reverse_rotate_b(&stack_b, 1);
		else if (ft_strncmp(instructions[i], "rrr", ft_strlen(instructions[i])))
			reverse_rotate_a_b(&stack_a, &stack_b);
		else if (ft_strncmp(instructions[i], "sa", ft_strlen(instructions[i])))
			swap_a(&stack_a);
		else if (ft_strncmp(instructions[i], "sb", ft_strlen(instructions[i])))
			swap_b(&stack_b);
		else if (ft_strncmp(instructions[i], "ss", ft_strlen(instructions[i])))
			swap_a_b(&stack_a, &stack_b);
		else if (ft_strncmp(instructions[i], "pa", ft_strlen(instructions[i])))
			push_a(&stack_a, &stack_b);
		else if (ft_strncmp(instructions[i], "pb", ft_strlen(instructions[i])))
			push_b(&stack_a, &stack_b);
		i++;
	}
	if (!is_it_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	i = 0;
	while (instructions[i])
	{
		free(instructions[i]);
		i++;
	}
	free(instructions);
	// if (!is_it_sorted(stack_a))
	// 	sorting(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
