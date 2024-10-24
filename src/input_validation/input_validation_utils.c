/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:32:28 by taung             #+#    #+#             */
/*   Updated: 2024/10/24 01:26:38 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	len_numbers(char **numbers)
{
	int	i;

	i = 0;
	while(numbers[i])
	{
		i++;
	}
	return (i);
}

int	duplicate_checker(char **inputs, char *numb, int index_i, int index_j)
{
	int		i;
	int		j;
	char**	numbers;

	i = index_i;
	while (inputs[i])
	{
		j = 0;
		numbers = ft_split((const char*)inputs[i], ' ');
		if (len_numbers(numbers) > 1)
			j = index_j + 1;
		while (numbers[j])
		{
			printf("inside is_duplicate numb: %s \t & j: %d\n",numbers[j],j);
			if(ft_atoi(numbers[j]) - ft_atoi(numb) == 0)
				return (0);
			j++;
		}
		free_inputs(numbers);
		numbers = NULL;
		i++;
	}
	printf("%s \t is validated\n",numb);
	return (1);
}

int	duplicate_helper(char **inputs, int i)
{
	int	j;
	char **numbers;

	j = 0;
	numbers = ft_split((const char*)inputs[i], ' ');
	while (numbers[j])
	{
		if (len_numbers(numbers) > 1)
		{
			if (!duplicate_checker(inputs, numbers[j], i, j))
				return (0);
		}
		if (len_numbers(numbers) == 1)
		{
			if (!duplicate_checker(inputs, numbers[j], i + 1, j))
				return (0);
		}
		j++;
	}
	free_inputs(numbers);
	numbers = NULL;
	return (1);
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
