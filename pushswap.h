/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:21:43 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/14 18:46:23 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include <limits.h>

int		is_it_integer(char *nbr);
int		check_numbers(int i, char **nbr);
int     check_duplicates(t_list *stack_a);
int		store_numbers(int ac, char **av, t_list **stack_a, t_list **temp_stack);

void	free_node(char **nbr);
void	print_stack(t_list **stack_a);

#endif
