/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:39:51 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/17 14:46:38 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	update_index(t_list *stack)
{
	int	i;
	int	half;

	if (!stack)
		return (0);
	half = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= half)
			stack->above_half = 1;
		else
			stack->above_half = 0;
		stack = stack->next;
		i++;
	}
	return (1);
}

int	update_stack_a(t_list *stack_a, t_list *stack_b)
{
	update_index(stack_a);
}
