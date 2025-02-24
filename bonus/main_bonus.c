/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:38:01 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/24 00:34:41 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
		
int	read_instructions(char **instructions)
{
	int		i;
	
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
	//function to check if there is something other than the operations
	ft_printf("Here are the Operations:\n");
	while (instructions[i])
	{
		ft_printf("Operation number %d: %s", i + 1, instructions[i]);
		i++;
	}
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
