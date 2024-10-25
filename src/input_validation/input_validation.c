/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:32:05 by taung             #+#    #+#             */
/*   Updated: 2024/10/25 20:06:03 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	is_number(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_limit(char *num)
{
	long	numb;

	numb = ft_atol((const char *)num);
	if (numb >= -2147483648 && numb <= 2147483647)
	{
		return (1);
	}
	return (0);
}

int	validation_helper(char **inputs, int (*validation_func)(char *))
{
	int		i;
	int		j;
	char	**numbers;

	i = 1;
	while (inputs[i])
	{
		numbers = ft_split(inputs[i], ' ');
		j = 0;
		while (numbers[j])
		{
			if (!(validation_func(numbers[j])))
				return (0);
			j++;
		}
		i++;
		free_inputs(numbers);
		numbers = NULL;
	}
	return (1);
}

int	is_duplicate(char **inputs)
{
	char	**all_numbers;
	int		i;
	int		j;

	i = 0;
	all_numbers = collect_numbers(inputs);
	while (all_numbers[i])
	{
		j = i + 1;
		while (all_numbers[j])
		{
			if (ft_atoi(all_numbers[i]) == ft_atoi(all_numbers[j]))
			{
				free_inputs(all_numbers);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_inputs(all_numbers);
	return (1);
}

int	validation(char **inputs)
{
	if (!validation_helper(inputs, &is_number))
	{
		ft_putstr_fd("Error !number\n", 2);
		return (0);
	}
	if (!validation_helper(inputs, &is_limit))
	{
		ft_putstr_fd("Error limit over\n", 2);
		return (0);
	}
	if (!is_duplicate(inputs))
	{
		ft_putstr_fd("Error duplicate inputs\n", 2);
		return (0);
	}
	return (1);
}
