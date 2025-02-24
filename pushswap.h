/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:21:43 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/24 21:12:29 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include <limits.h>

/***********PARSING AND CHECKING***********/

int		store_and_check(int ac, char **av, t_list **stack_a);
int		store_numbers(int ac, char **av, t_list **stack_a);

int		check_duplicates(t_list *stack_a);
int		is_it_sorted(t_list *stack_a);

int		check_numbers(int i, char **nbr);

int		is_it_integer(char *nbr);

void	free_node(char **nbr);
void	print_stack(t_list *stack_a);

//****************\\//OPERATIONS\\//****************//

/*******************SWAP*******************/

int		swap_a(t_list **stack_a);
int		swap_b(t_list **stack_b);
int		swap_a_b(t_list **stack_a, t_list **stack_b);

/*******************PUSH*******************/

int		push_a(t_list **stack_a, t_list **stack_b);
int		push_b(t_list **stack_a, t_list **stack_b);

/*******************ROTATE*******************/

int		rotate_a(t_list **stack_a, int flag);
int		rotate_b(t_list **stack_b, int flag);
int		rotate_a_b(t_list **stack_a, t_list **stack_b);

/*******************REVERSE_ROTATE*******************/

t_list	*ft_lst_second_last(t_list *stack_a, t_list *temp_stack);

int		reverse_rotate_a(t_list **stack_a, int flag);
int		reverse_rotate_b(t_list **stack_b, int flag);
int		reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);

//***********************//\\//\\***********************//

/*******************SORTING*******************/

int		sorting(t_list **stack_a, t_list **stack_b);
int		sort_big(t_list **stack_a, t_list **stack_b);
int		sort_three(t_list **stack);

/*******************UPDATING*******************/

int		putting_min_top(t_list **stack);

int		update_index(t_list *stack);
int		update_rank(t_list *stack);
int		update_stack_b(t_list **stack_a, t_list **stack_b);

/*******************FIND MIN AND MAX*******************/

t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);

/*******************SET TARGET*******************/

int		set_target_stack_a(t_list *stack_a, t_list *stack_b);
int		find_closest_min(t_list *a, t_list *b, long *closest_small);

int		set_target_stack_b(t_list *stack_a, t_list *stack_b);
int		find_closest_max(t_list *a, t_list *b, long *closest_big);

/*******************FIND CHEAP AND COST*******************/

int		set_cost(t_list *stack_a, t_list *stack_b);
int		find_cheapest(t_list *stack);

t_list	*get_cheapest_node(t_list *stack);

/*******************DUMPING*******************/

int		prepare_stack_a(t_list **stack_a, t_list *cheapest);
int		prepare_stack_b(t_list **stack_b, t_list *cheapest);
int		dumping_stack_a(t_list **stack_a, t_list **stack_b);
int		dumping_stack_b(t_list **stack_a, t_list **stack_b);

/*******************FINISHING*******************/

int		putting_min_top(t_list **stack);

/*******************BONUS*******************/

int		read_operations(t_list **stack_a, t_list **stack_b);

int		follow_operations(char *op, t_list **stack_a, t_list **stack_b);

int		swaping(char *op, t_list **stack_a, t_list **stack_b);
int		pushing(char *op, t_list **stack_a, t_list **stack_b);
int		rotations(char *op, t_list **stack_a, t_list **stack_b);
int		rev_rotations(char *op, t_list **stack_a, t_list **stack_b);

#endif
