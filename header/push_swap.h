#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>

typedef struct s_dict
{
	int *values;
	int *keys;
	size_t len;
}	ft_dict;

typedef struct s_inputs
{
	int *inputs;
	size_t len;
}	ft_inputs;

typedef struct s_vali_info
{
	char	**inputs;
}	t_vali_info;
//dictionary
void	ft_make_dict(int *value, int *key, ft_dict *dict, size_t len);
void	ft_print_dict(ft_dict *dict);
int		ft_find_value(ft_dict *dict, int key);

//discretization
int	ft_calc_key(int value, ft_inputs *inputs);
int	*ft_discretize(ft_inputs *inputs);

//test utils
void	ft_print_arr(int *arr, size_t len);

//input validations
int	validation(char **inputs);

//input validation utils
int	is_number(char *str);
int	is_limit(char *str);
int	is_duplicate(char **inputs, char *numb, int index_i, int index_j);
int	len_numbers(char **numbers);

// free
void	free_inputs(char **inputs);
#endif
