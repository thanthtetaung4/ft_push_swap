/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:32:05 by taung             #+#    #+#             */
/*   Updated: 2024/10/22 21:44:18 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	validation_checks(char **numbs, char *numb, int i, int j)
{
	// printf("%s\n",numb);
	if(!is_number(numb))
	{
		ft_putstr_fd("Error !number\n", 2);
		return (0);
	}
	if(!is_limit(numb))
	{
		ft_putstr_fd("Error over the limit\n", 2);
		return (0);
	}
	if(!is_duplicate(numbs, numb, i, j))
	{
		ft_putstr_fd("Error duplicate\n", 2);
		return 0;
	}
	return (1);
}
int	validation_helper()
{

}
// multi inputs validation
int	validation(char **inputs)
{
	int		i;
	int		j;
	char**	numbers;

	i = 1;
	while (inputs[i])
	{
		j = 0;
		numbers = ft_split((const char*)inputs[i], ' ');
		while (numbers[j])
		{
			printf("validating number: %s \t j: %d\n", numbers[j],j);
			if (len_numbers(numbers) > 1)
			{
				if (!validation_checks(inputs, numbers[j], i, j))
					return (0);
			}
			if (len_numbers(numbers) == 1)
			{
				if (!validation_checks(inputs, numbers[j], i + 1, j))
					return (0);
			}
			j++;
		}
		free_inputs(numbers);
		numbers = NULL;
		i++;
	}
	return (1);
}


