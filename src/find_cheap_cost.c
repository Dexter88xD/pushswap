/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheap_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:24:14 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/19 09:28:42 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int set_cost(t_list *stack_a, t_list *stack_b)
{
	int	a_size;
	int	b_size;

	a_size = ft_lstsize(stack_a);
	b_size = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->above_half))
			stack_a->cost = a_size - stack_a->index;
		if (!(stack_a->target->above_half))
			stack_a->target->cost += b_size - stack_a->target->index;
		else
			stack_a->target->cost += stack_a->target->index;
		stack_a = stack_a->next;
	}
    return (1);
}

int	find_cheapest(t_list *stack)
{
	int		cheap_value;
	t_list	*cheap_node;

	cheap_value = INT_MAX;
	while (stack)
	{
		if (stack->cost < cheap_value)
		{
			cheap_node = stack;
			cheap_value = stack->cost;
		}
		stack = stack->next;
	}
	cheap_node->cheap = 1;
	return (1);
}

t_list  *get_cheapest_node(t_list *stack)
{
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
