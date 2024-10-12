/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discretize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:31:44 by taung             #+#    #+#             */
/*   Updated: 2024/10/07 12:42:12 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	ft_calc_key(int value, ft_inputs *inputs)
{
	int		key;
	size_t	i;

	i = 0;
	key = 0;
	while(i < inputs->len)
	{
		if (value > inputs->inputs[i])
			key++;
		i++;
	}

	return key;
}

// covert the input array of int to 0,1,2,...,n 0 being the smallest and n being the largest
int	*ft_discretize(ft_inputs *inputs)
{
	int		*keys;
	size_t	i;

	keys = malloc(sizeof(int) * inputs->len);
	i = 0;
	if(!keys)
		return NULL;
	while(i < inputs->len)
	{
		keys[i] = ft_calc_key(inputs->inputs[i], inputs);
		i++;
	}

	return keys;
}

int main()
{
	int user_inputs[5] = {-5,3,2,-1,0};

	ft_inputs *inputs = malloc(sizeof(ft_inputs));
	inputs->inputs = user_inputs;
	inputs->len = 5;

	int *keys = ft_discretize(inputs);
	ft_print_arr(keys,inputs->len);
}
