/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumping_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:43:05 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/23 16:59:59 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	prepare_stack_a(t_list **stack_a, t_list *cheapest)
{
	while (*stack_a != cheapest)
	{
		if (cheapest->above_half)
			rotate_a(stack_a, 0);
		else
			reverse_rotate_a(stack_a, 0);
	}
	return (1);
}

int	prepare_stack_b(t_list **stack_b, t_list *target)
{
	while (*stack_b != target)
	{
		if (target->above_half)
			rotate_b(stack_b, 0);
		else
			reverse_rotate_b(stack_b, 0);
	}
	return (1);
}

int	dumping_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	half;
	int	size;

	size = ft_lstsize(*stack_a);
	if (size < 150)
		half = size / 2;
	else
		half = size / 3;
	while ((*stack_a)->rank > half)
		rotate_a(stack_a, 0);
	push_b(stack_a, stack_b);
	return (1);
}

int	dumping_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = get_cheapest_node(*stack_b);
	if (cheapest->above_half && cheapest->target->above_half)
	{
		while (*stack_b != cheapest && *stack_a != cheapest->target)
			rotate_a_b(stack_a, stack_b);
		update_index(*stack_a);
		update_index(*stack_b);
	}
	else if (!(cheapest->above_half) && !(cheapest->target->above_half))
	{
		while (*stack_b != cheapest && *stack_a != cheapest->target)
			reverse_rotate_a_b(stack_a, stack_b);
		update_index(*stack_a);
		update_index(*stack_b);
	}
	prepare_stack_b(stack_b, cheapest);
	prepare_stack_a(stack_a, cheapest->target);
	push_a(stack_a, stack_b);
	return (1);
}
