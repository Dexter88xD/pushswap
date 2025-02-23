/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:13:33 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/23 17:31:46 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*p;

	i = 0;
	p = NULL;
	while (*s)
	{
		if (s[i] == (unsigned char)c)
			p = s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	else if ((unsigned char)c != '\0')
		return ((char *)p);
	return (NULL);
}
