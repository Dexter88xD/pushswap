/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:21:28 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/19 16:33:22 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	find_closest_min(t_list *a, t_list *b, long *closest_small)
{
	if (b->content < a->content)
	{
		if (*closest_small > a->content || (*closest_small < a->content
				&& *closest_small < b->content))
		{
			*closest_small = b->content;
			a->target = b;
		}
	}
	return (1);
}

int	set_target_stack_a(t_list *stack_a, t_list *stack_b)
{
	long	closest_small;
	t_list	*temp_b;

	if (!stack_a || !stack_b)
		return (0);
	while (stack_a)
	{
		closest_small = LONG_MAX;
		temp_b = stack_b;
		while (temp_b)
		{
			find_closest_min(stack_a, temp_b, &closest_small);
			temp_b = temp_b->next;
		}
		if (closest_small == LONG_MAX)
			stack_a->target = find_max(stack_b);
		stack_a = stack_a->next;
	}
	return (1);
}

int	find_closest_max(t_list *a, t_list *b, long *closest_big)
{
	if (a->content > b->content)
	{
		if (*closest_big < b->content || (*closest_big > b->content
				&& *closest_big > a->content))
		{
			*closest_big = a->content;
			b->target = a;
		}
	}
	return (1);
}

int	set_target_stack_b(t_list *stack_a, t_list *stack_b)
{
	long	closeset_big;
	t_list	*temp_a;

	if (!stack_a || !stack_b)
		return (0);
	while (stack_b)
	{
		closeset_big = LONG_MIN;
		temp_a = stack_a;
		while (temp_a)
		{
			find_closest_max(temp_a, stack_b, &closeset_big);
			temp_a = temp_a->next;
		}
		if (closeset_big == LONG_MIN)
			stack_b->target = find_min(stack_a);
		stack_b = stack_b->next;
	}
	return (1);
}
