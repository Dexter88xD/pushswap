/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 05:13:58 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/17 14:41:24 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	sort_three(t_list **stack_a)
{
	t_list	*second_node;
	t_list	*last_node;

	second_node = (*stack_a)->next;
	last_node = (*stack_a)->next->next;
	if ((*stack_a)->content > second_node->content)
	{
		if ((*stack_a)->content < last_node->content)
			swap_a(stack_a);
		else if (second_node->content < last_node->content)
			rotate_a(stack_a);
		else
			((rotate_a(stack_a)), (swap_a(stack_a)));
	}
	else
	{
		if ((*stack_a)->content > last_node->content)
			reverse_rotate_a(stack_a);
		else
			((swap_a(stack_a)), (rotate_a(stack_a)));
	}
	return (1);
}

int	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	stack_a_size;

	stack_a_size = ft_lstsize(*stack_a);
	if (stack_a_size-- && !is_it_sorted(*stack_a))
		push_a(stack_a, stack_b);
	if (stack_a_size-- && !is_it_sorted(*stack_a))
		push_a(stack_a, stack_b);
	while (stack_a_size-- && !is_it_integer(*stack_a))
	{
		update_stack_a(*stack_a, *stack_b);
		push_a(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		update_stack_b(*stack_a, *stack_b);
		push_b(stack_a, stack_b);
	}
	update_index(*stack_a);
	putting_min_top(stack_a);
	return (1);
}

int	sorting(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (ft_lstsize(*stack_a) == 2)
		swap_a(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a, stack_b);
	return (0);
}
