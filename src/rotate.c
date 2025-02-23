/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:17:53 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/23 15:45:25 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	rotate_a(t_list **stack_a, int flag)
{
	t_list	*temp_stack;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	temp_stack = *stack_a;
	*stack_a = (*stack_a)->next;
	temp_stack->next = NULL;
	ft_lstadd_back(stack_a, temp_stack);
	if (!flag)
		ft_printf("ra\n");
	return (1);
}

int	rotate_b(t_list **stack_b, int flag)
{
	t_list	*temp_stack;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	temp_stack = *stack_b;
	*stack_b = (*stack_b)->next;
	temp_stack->next = NULL;
	ft_lstadd_back(stack_b, temp_stack);
	if (!flag)
		ft_printf("rb\n");
	return (1);
}

int	rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return (0);
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
	ft_printf("rr\n");
	return (1);
}
