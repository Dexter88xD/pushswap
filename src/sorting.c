/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 05:13:58 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/17 08:41:12 by sohamdan         ###   ########.fr       */
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

int	sorting(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (ft_lstsize(*stack_a) == 2)
		swap_a(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else
		ft_printf("More than three, to be done later!\n");
	return (0);
}
