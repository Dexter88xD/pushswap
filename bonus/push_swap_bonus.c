/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:18:25 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/24 00:55:53 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_stack;

	if (!stack_a || !stack_b || !*stack_b)
		return (0);
	temp_stack = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, temp_stack);
	return (1);
}

int	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_stack;

	if (!stack_a || !*stack_a || !stack_b)
		return (0);
	temp_stack = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, temp_stack);
	return (1);
}

int	swap_a(t_list **stack_a)
{
	int	temp;

	if (!stack_a || ft_lstsize(*stack_a) < 2)
		return (0);
	temp = (*stack_a)->next->content;
	(*stack_a)->next->content = (*stack_a)->content;
	(*stack_a)->content = temp;
	return (1);
}

int	swap_b(t_list **stack_b)
{
	int	temp;

	if (!stack_b || ft_lstsize(*stack_b) < 2)
		return (0);
	temp = (*stack_b)->next->content;
	(*stack_b)->next->content = (*stack_b)->content;
	(*stack_b)->content = temp;
	return (1);
}

int	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return (0);
	swap_a(stack_a);
	swap_b(stack_b);
	return (1);
}
