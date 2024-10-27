/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:48:34 by taung             #+#    #+#             */
/*   Updated: 2024/10/27 19:10:28 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_numbers
{
	int	*numbers;
	int	len;
}	t_numbers;

//discretization
void		set_index(t_list **stack_a, int len);

//test utils
void		ft_print_arr(int *arr, size_t len);

//input validations
int			validation(char **inputs);

//input validation utils
int			is_number(char *number);
int			is_limit(char *number);
int			is_duplicate(char **inputs);
int			duplicate_helper(char **inputs, int i);
char		**collect_numbers(char **inputs);
int			len_numbers(char **numbers);
int			get_total_numbers(char **inputs);
int			is_not_empty(char **inputs);
int			is_sorted(t_list **lst);

// free
void		free_inputs(char **inputs);

//general utils
long		ft_atol(const char *nptr);
void		print_list(t_list *list);
void		do_nth(void *tlist);

//init
t_numbers	init_numbers(char **inputs);
t_list		*init_stack(t_numbers numbers);

//operations
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);

//sorting methods
void		sort_two(t_list **stack_a);
void		sort_three(t_list **stack_a, t_list **stack_b);
void		sort_four(t_list **stack_a, t_list **stack_b);
void		sort_five(t_list **stack_a, t_list **stack_b);
void		radix_sort(t_list **stack_a, t_list **stack_b, int len);

//sroting utils
void		sort_condition_five(t_list **stack_a,
				t_list **stack_b, int *values, int smallest);
void		sorting_five_helper(t_list **stack_a, t_list **stack_b);

//sorting helpers
void		sorting(t_list **stack_a, t_list **stack_b,
				void (f)(t_list **, t_list **));
int			find_smallest(int *values, int len);
void		sort_four_condition(t_list **stack_a,
				t_list **stack_b, int *values, int smallest);
int			find_smallest(int *values, int len);

//sort
void		sort(t_list **stack_a, t_list **stack_b, t_numbers numbers);

#endif
