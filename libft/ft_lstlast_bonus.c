/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:56:54 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/15 17:47:00 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;
	t_list	*previous;

	if (!lst)
		return (NULL);
	current = lst;
	previous = current;
	while (current != NULL)
	{
		current = (*current).next;
		if (current != NULL)
			previous = current;
	}
	return (previous);
}
