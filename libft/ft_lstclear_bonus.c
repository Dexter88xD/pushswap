/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 05:47:59 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/14 18:12:04 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*previous;

	current = (*lst);
	if (lst)
	{
		while (current != NULL)
		{
			previous = current;
			current = (*current).next;
			free(previous);
		}
		(*lst) = NULL;
	}
}
