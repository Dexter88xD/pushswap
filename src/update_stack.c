/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:39:51 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/19 11:42:14 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	putting_min_top(t_list **stack)
{
	t_list	*minimum;

	minimum = find_min(*stack);		
	while (*stack != minimum)
	{
		if (minimum->above_half)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
	return (1);
}

int	update_index(t_list *stack)
{
	int		i;
	int		half;

	if (!stack || !stack->next)
		return (0);
	i = 0;
	half = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < half)
			stack->above_half = 1;
		else
			stack->above_half = 0;
		stack = stack->next;
		i++;
	}
	return (1);
}

int	update_stack_a(t_list **stack_a, t_list **stack_b)
{
	update_index(*stack_a);
	update_index(*stack_b);
	set_target_stack_a(*stack_a, *stack_b);
	set_cost(*stack_a, *stack_b);
	find_cheapest(*stack_a);
	return (1);
}

int	update_stack_b(t_list **stack_a, t_list **stack_b)
{
	update_index(*stack_a);
	update_index(*stack_b);
	set_target_stack_b(*stack_a, *stack_b);
	return (1);
}
