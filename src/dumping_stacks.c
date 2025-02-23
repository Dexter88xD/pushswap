/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumping_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:43:05 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/23 16:44:51 by sohamdan         ###   ########.fr       */
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
	t_list	*cheapest;

	cheapest = get_cheapest_node(*stack_a);
	if (cheapest->above_half && cheapest->target->above_half)
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target)
			rotate_a_b(stack_a, stack_b);
		update_index(*stack_a);
		update_index(*stack_b);
	}
	else if (!(cheapest->above_half) && !(cheapest->target->above_half))
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target)
			reverse_rotate_a_b(stack_a, stack_b);
		update_index(*stack_a);
		update_index(*stack_b);
	}
	prepare_stack_a(stack_a, cheapest);
	prepare_stack_b(stack_b, cheapest->target);
	push_b(stack_a, stack_b);
	return (1);
}

int	dumping_stack_b(t_list **stack_a, t_list **stack_b)
{
	prepare_stack_a(stack_a, (*stack_b)->target);
	push_a(stack_a, stack_b);
	return (1);
}
