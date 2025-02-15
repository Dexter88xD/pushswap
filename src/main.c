/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:16:35 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/15 21:37:18 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	free_node(char	**nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
		free(nbr[i++]);
	free(nbr);
}

void	print_stack(t_list *stack)
{
	t_list	*temp_stack;
	int		a;

	a = 1;
	temp_stack = stack;
	while (temp_stack)
	{
		ft_printf("The argument number %d: %d\n", a++,
			temp_stack->content);
		temp_stack = temp_stack->next;
	}
}

int	store_numbers(int ac, char **av, t_list **stack_a, t_list **temp_stack)
{
	int		i;
	int		numb;
	int		temp;
	char	**nbr;

	numb = 1;
	while (numb < ac)
	{
		i = 0;
		nbr = ft_split(av[numb], ' ');
		while (nbr[i])
		{
			if (check_numbers(i, nbr) == 1)
				return (ft_printf("Error\n"), free_node(nbr), 1);
			temp = ft_atoi(nbr[i]);
			*temp_stack = ft_lstnew(temp);
			ft_lstadd_back(stack_a, *temp_stack);
			i++;
		}
		free_node(nbr);
		numb++;
	}
	if (check_duplicates(*stack_a) == 1)
		return (ft_printf("Error\n"), ft_lstclear(stack_a), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp_stack;

	if (ac < 2)
		return (ft_printf("Please provide the numbers to be sorted!\n"), 1);
	stack_a = NULL;
	stack_b = NULL;
	if (store_numbers(ac, av, &stack_a, &temp_stack) == 1)
		return (1);
	return (0);
}
