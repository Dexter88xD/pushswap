/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:43:46 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/23 17:29:58 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sym;

	i = 0;
	sym = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		sym = -sym;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr > 47 && *nptr < 58)
	{
		i = (*nptr - 48) + i * 10;
		nptr++;
	}
	return (i * sym);
}
