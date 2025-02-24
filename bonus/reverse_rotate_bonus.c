/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:18:08 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/24 00:56:52 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_list	*ft_lst_second_last(t_list *stack_a, t_list *temp_stack)
{
	t_list	*last_stack;
	t_list	*second_last_stack;

	last_stack = stack_a;
	second_last_stack = last_stack;
	while (last_stack != temp_stack)
	{
		last_stack = last_stack->next;
		if (last_stack != temp_stack)
			second_last_stack = last_stack;
	}
	return (second_last_stack);
}

int	reverse_rotate_a(t_list **stack_a, int flag)
{
	t_list	*temp_stack;
	t_list	*last_stack;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	temp_stack = ft_lstlast(*stack_a);
	last_stack = ft_lst_second_last(*stack_a, temp_stack);
	last_stack->next = NULL;
	ft_lstadd_front(stack_a, temp_stack);
	if (!flag)
		flag = 1;
	return (1);
}

int	reverse_rotate_b(t_list **stack_b, int flag)
{
	t_list	*temp_stack;
	t_list	*last_stack;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	temp_stack = ft_lstlast(*stack_b);
	last_stack = ft_lst_second_last(*stack_b, temp_stack);
	last_stack->next = NULL;
	ft_lstadd_front(stack_b, temp_stack);
	if (!flag)
		flag = 1;
	return (1);
}

int	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return (0);
	reverse_rotate_a(stack_a, 1);
	reverse_rotate_b(stack_b, 1);
	return (1);
}
