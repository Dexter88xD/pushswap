/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:16:35 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/14 18:51:42 by sohamdan         ###   ########.fr       */
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
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
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
	while (*nbr >= '0' && *nbr <= '9')
	{
		check = (*nbr - '0') + check * 10;
		nbr++;
	}
	check *= sign;
	if (check < INT_MIN || check > INT_MAX)
		return (1);
	return (0);
}

int	check_numbers(int i, char **nbr)
{
	int	j;

	j = 0;
	if (nbr[i][j] == '-' || nbr[i][j] == '+')
		j++;
	if (nbr[i][j] == '\0')
		return (1);
	while (nbr[i][j])
	{
		if (!(nbr[i][j] >= '0' && nbr[i][j] <= '9'))
			return (1);
		j++;
	}
	return (is_it_integer(nbr[i]));
}
