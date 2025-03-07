/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:16:35 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/07 15:09:14 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	check_duplicates(t_list *stack_a)
{
	t_list	*current;
	t_list	*next;

	current = stack_a;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->content == next->content)
				return (0);
			next = next->next;
		}
		current = current->next;
	}
	return (1);
}

int	is_it_integer(char *nbr)
{
	long	check;
	int		sign;

	check = 0;
	sign = 1;
	if (*nbr == '-')
	{
		nbr++;
		sign = -sign;
	}
	else if (*nbr == '+')
		nbr++;
	while (*nbr == '0')
		nbr++;
	if (ft_strlen(nbr) > 11)
		return (0);
	while (*nbr >= '0' && *nbr <= '9')
	{
		check = (*nbr - '0') + check * 10;
		nbr++;
	}
	check *= sign;
	if (check < INT_MIN || check > INT_MAX)
		return (0);
	return (1);
}

int	is_it_sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_numbers(int i, char **nbr)
{
	int	j;

	j = 0;
	if (nbr[i][j] == '-' || nbr[i][j] == '+')
		j++;
	if (nbr[i][j] == '\0')
		return (0);
	while (nbr[i][j])
	{
		if (!(nbr[i][j] >= '0' && nbr[i][j] <= '9'))
			return (0);
		j++;
	}
	return (is_it_integer(nbr[i]));
}
