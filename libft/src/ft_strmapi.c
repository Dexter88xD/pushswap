/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:23:40 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/23 17:31:40 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*results;
	int		len;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	results = (char *)malloc((len + 1) * sizeof(char));
	if (results == NULL)
		return (NULL);
	while (s[i])
	{
		results[i] = (*f)(i, s[i]);
		i++;
	}
	results[i] = '\0';
	return (results);
}
