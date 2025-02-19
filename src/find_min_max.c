/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 07:40:37 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/18 08:20:48 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_list	*find_max(t_list *stack)
{
	t_list	*max;
	int		max_num;

	max_num = INT_MIN;
	while (stack)
	{
		if (stack->content > max_num)
		{
			max_num = stack->content;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_list	*find_min(t_list *stack)
{
	t_list	*min;
	int		min_num;

	min_num = INT_MAX;
	while (stack)
	{
		if (stack->content > min_num)
		{
			min_num = stack->content;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

int	find_min_num(t_list *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	find_max_num(t_list *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}
