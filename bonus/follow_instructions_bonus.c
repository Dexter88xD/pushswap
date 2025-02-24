/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_instructions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:04:35 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/24 13:37:08 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	rev_rotations(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "rra\n", 4))
	{
		reverse_rotate_a(stack_a, 1);
		return (1);
	}
	else if (!ft_strncmp(op, "rrb\n", 4))
	{
		reverse_rotate_b(stack_b, 1);
		return (1);
	}
	else if (!ft_strncmp(op, "rrr\n", 4))
	{
		reverse_rotate_a_b(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	rotations(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "ra\n", 3))
	{
		rotate_a(stack_a, 1);
		return (1);
	}
	else if (!ft_strncmp(op, "rb\n", 3))
	{
		rotate_b(stack_b, 1);
		return (1);
	}
	else if (!ft_strncmp(op, "rr\n", 3))
	{
		rotate_a_b(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	pushing(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "pa\n", 3))
	{
		push_a(stack_a, stack_b);
		return (1);
	}
	else if (!ft_strncmp(op, "pb\n", 3))
	{
		push_b(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	swaping(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "sa\n", 3))
	{
		swap_a(stack_a);
		return (1);
	}
	else if (!ft_strncmp(op, "sb\n", 3))
	{
		swap_b(stack_b);
		return (1);
	}
	else if (!ft_strncmp(op, "ss\n", 3))
	{
		swap_a_b(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	follow_operations(char *op, t_list **stack_a, t_list **stack_b)
{
	if (rotations(op, stack_a, stack_b))
		return (1);
	if (rev_rotations(op, stack_a, stack_b))
		return (1);
	if (pushing(op, stack_a, stack_b))
		return (1);
	if (swaping(op, stack_a, stack_b))
		return (1);
	return (0);
}
