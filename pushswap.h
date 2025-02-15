/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:21:43 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/15 21:23:37 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include <limits.h>

/*******************PARSING*******************/

int		is_it_integer(char *nbr);
int		check_numbers(int i, char **nbr);
int		check_duplicates(t_list *stack_a);
int		store_numbers(int ac, char **av, t_list **stack_a, t_list **temp_stack);

void	free_node(char **nbr);
void	print_stack(t_list *stack_a);

//****************//OPERATIONS//****************//

/*******************SWAP*******************/

int		swap_a(t_list **stack_a);
int		swap_b(t_list **stack_b);
int		swap_a_b(t_list **stack_a, t_list **stack_b);

/*******************PUSH*******************/

int		push_a(t_list **stack_a, t_list **stack_b);
int		push_b(t_list **stack_a, t_list **stack_b);

/*******************ROTATE*******************/

int		rotate_a(t_list **stack_a);
int		rotate_b(t_list **stack_b);
int		rotate_a_b(t_list **stack_a, t_list **stack_b);

/*******************REVERSE_ROTATE*******************/

t_list	*ft_lst_second_last(t_list *stack_a, t_list *temp_stack);

int		reverse_rotate_a(t_list **stack_a);
int		reverse_rotate_b(t_list **stack_b);
int		reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);

//*******************////*******************//

#endif
