/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:32:28 by taung             #+#    #+#             */
/*   Updated: 2024/10/24 17:20:10 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int len_numbers(char **numbers)
{
	int i;

	i = 0;
	while (numbers[i])
	{
		i++;
	}
	return (i);
}

int	get_total_numbers(char **inputs)
{
	int		i;
	int		len;
	char	**temp;

	i = 1;
	len = 0;
	while (inputs[i])
	{
		temp = ft_split(inputs[i], ' ');
		len += len_numbers(temp);
		free_inputs(temp);
		i++;
	}
	return len;
}

char**	get_all_numbers(char **inputs)
{
	int i;
	int len;
	char **temp;
	char **all_numbers;

	i = 1;
	len = get_total_numbers(inputs);
	all_numbers = malloc(sizeof(char *) * (len + 1));
	if (!all_numbers)
		return NULL;
	return (all_numbers);
}

char **collect_numbers(char **inputs)
{
	char **all_numbers;
	int i = 1;
	int total_count;
	char **temp;
	int j;

	total_count = 0;
	i = 1;
	all_numbers = get_all_numbers(inputs);
	while (inputs[i])
	{
		temp = ft_split(inputs[i], ' ');
		j = 0;
		while (temp[j])
		{
			all_numbers[total_count] = ft_strdup(temp[j]);
			total_count++;
			j++;
		}
		free_inputs(temp);
		i++;
	}
	all_numbers[total_count] = NULL;
	return all_numbers;
}

// #include <limits.h>
// int	main()
// {
// 	char *str = "2147483650";
// 	long numb = ft_atol(str);
// 	numb = 2147483650;
// 	printf("numb: %ld\n", numb);

// 	if (is_limit(str))
// 		printf("in range\n");
// }
