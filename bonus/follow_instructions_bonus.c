/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_instructions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:04:35 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/24 01:17:31 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	rev_rotations(char **instr, t_list **stack_a, t_list **stack_b,
		int i)
{
	if (ft_strncmp(instr[i], "rra", ft_strlen(instr[i])))
	{
		reverse_rotate_a(stack_a, 1);
		return (1);
	}
	else if (ft_strncmp(instr[i], "rrb", ft_strlen(instr[i])))
	{
		reverse_rotate_b(stack_b, 1);
		return (1);
	}
	else if (ft_strncmp(instr[i], "rrr", ft_strlen(instr[i])))
	{
		reverse_rotate_a_b(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	rotations(char **instr, t_list **stack_a, t_list **stack_b, int i)
{
	if (ft_strncmp(instr[i], "ra", ft_strlen(instr[i])))
	{
		rotate_a(stack_a, 1);
		return (1);
	}
	else if (ft_strncmp(instr[i], "rb", ft_strlen(instr[i])))
	{
		rotate_b(stack_b, 1);
		return (1);
	}
	else if (ft_strncmp(instr[i], "rr", ft_strlen(instr[i])))
	{
		rotate_a_b(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	pushing(char **instr, t_list **stack_a, t_list **stack_b, int i)
{
	if (ft_strncmp(instr[i], "pa", ft_strlen(instr[i])))
	{
		push_a(stack_a, stack_b);
	}
	else if (ft_strncmp(instr[i], "pb", ft_strlen(instr[i])))
	{
		push_b(stack_a, stack_b);
	}
	return (0);
}

int	swaping(char **instr, t_list **stack_a, t_list **stack_b, int i)
{
	if (ft_strncmp(instr[i], "sa", ft_strlen(instr[i])))
	{
		swap_a(stack_a);
	}
	else if (ft_strncmp(instr[i], "sb", ft_strlen(instr[i])))
	{
		swap_b(stack_b);
	}
	else if (ft_strncmp(instr[i], "ss", ft_strlen(instr[i])))
	{
		swap_a_b(stack_a, stack_b);
	}
	return (0);
}

int	follow_instructions(char **instr, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	check;

	i = 0;
	while (instr[i])
	{
		check = rotations(instr, stack_a, stack_b, i);
		if (!check)
			check = rev_rotations(instr, stack_a, stack_b, i);
		if (!check)
			check = pushing(instr, stack_a, stack_b, i);
		if (!check)
			check = swaping(instr, stack_a, stack_b, i);
		i++;
	}
	return (0);
}
