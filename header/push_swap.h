#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>

typedef struct s_numbers
{
	int	*numbers;
	int	len;
}	t_numbers;

//dictionary
// void	ft_make_dict(int *value, int *key, ft_dict *dict, size_t len);
// void	ft_print_dict(ft_dict *dict);
// int		ft_find_value(ft_dict *dict, int key);

// //discretization
// int	ft_calc_key(int value, ft_inputs *inputs);
// int	*ft_discretize(ft_inputs *inputs);

//test utils
void	ft_print_arr(int *arr, size_t len);

//input validations
int	validation(char **inputs);

//input validation utils
int	is_number(char *number);
int	is_limit(char *number);
int	is_duplicate(char **inputs);
int	duplicate_helper(char **inputs, int i);
char **collect_numbers(char **inputs);
int	len_numbers(char **numbers);
int	get_total_numbers(char **inputs);

// free
void	free_inputs(char **inputs);

//general utils
long	ft_atol(const char *nptr);
void	print_list(t_list *list);
void	do_nth(void *tlist);

//init
t_numbers	init_numbers(char **inputs);
t_list	*init_stack(t_numbers numbers);

#endif
