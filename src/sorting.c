/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 05:13:58 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/19 11:05:44 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	sort_three(t_list **stack)
{
	t_list	*second_node;
	t_list	*last_node;

	second_node = (*stack)->next;
	last_node = (*stack)->next->next;
	if ((*stack)->content > second_node->content)
	{
		if ((*stack)->content < last_node->content)
			swap_a(stack);
		else if (second_node->content < last_node->content)
			rotate_a(stack);
		else
			((rotate_a(stack)), (swap_a(stack)));
	}
	else
	{
		if ((*stack)->content > last_node->content)
			reverse_rotate_a(stack);
		else
			((swap_a(stack)), (rotate_a(stack)));
	}
	return (1);
}

int	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	stack_a_size;

	stack_a_size = ft_lstsize(*stack_a);
	if (stack_a_size-- > 3 && !is_it_sorted(*stack_a))
		push_b(stack_a, stack_b);
	ft_printf("Stack a:\n");
	print_stack(*stack_a);
	ft_printf("Stack b\n");
	print_stack(*stack_b);
	if (stack_a_size-- > 3 && !is_it_sorted(*stack_a))
		push_b(stack_a, stack_b);
	ft_printf("Stack a:\n");
	print_stack(*stack_a);
	ft_printf("Stack b\n");
	print_stack(*stack_b);
	while (stack_a_size-- > 3 && !is_it_sorted(*stack_a))
	{
		update_stack_a(stack_a, stack_b);
		dumping_stack_a(stack_a, stack_b);
		ft_printf("Stack a:\n");
		print_stack(*stack_a);
		ft_printf("Stack b\n");
		print_stack(*stack_b);
	}
	sort_three(stack_a);
	ft_printf("Stack a:\n");
	print_stack(*stack_a);
	ft_printf("Stack b\n");
	print_stack(*stack_b);
	while (*stack_b)
	{
		update_stack_b(stack_a, stack_b);
		dumping_stack_b(stack_a, stack_b);
		ft_printf("Stack a:\n");
		print_stack(*stack_a);
		ft_printf("Stack b\n");
		print_stack(*stack_b);
	}
	update_index(*stack_a);
	putting_min_top(stack_a);
	return (1);
}

int	sorting(t_list **stack_a, t_list **stack_b)
{
	// t_list	*temp_stack;

	ft_printf("Stack b:\nEmpty\n");
	ft_printf("\n");
	if (ft_lstsize(*stack_a) == 2)
		swap_a(stack_a);
	// else if (ft_lstsize(*stack_a) == 3)
	// 	sort_three(stack_a);
	else
	{
		// ft_printf("Working on it, be patient!\n");
		sort_big(stack_a, stack_b);
		ft_printf("AFTER\n");
		ft_printf("Stack a:\n");
		print_stack(*stack_a);
		ft_printf("\n");
		ft_printf("Stack b:\n");
		print_stack(*stack_b);
		ft_printf("\n");
	}
	// sort_big(stack_a, stack_b);
	return (0);
}
