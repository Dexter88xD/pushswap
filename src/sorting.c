/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 05:13:58 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/23 17:37:06 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	sort_three(t_list **stack)
{
	t_list	*max;

	max = find_max(*stack);
	if ((*stack) == max)
		rotate_a(stack, 0);
	else if ((*stack)->next == max)
		reverse_rotate_a(stack, 0);
	if ((*stack)->content > (*stack)->next->content)
		swap_a(stack);
	return (1);
}

int	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	stack_a_size;

	stack_a_size = ft_lstsize(*stack_a);
	while (stack_a_size-- > 3 && !is_it_sorted(*stack_a))
	{
		update_rank(*stack_a);
		dumping_stack_a(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		update_stack_b(stack_a, stack_b);
		dumping_stack_b(stack_a, stack_b);
	}
	update_index(*stack_a);
	putting_min_top(stack_a);
	return (1);
}

int	sorting(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		swap_a(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a, stack_b);
	return (1);
}
