/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:32:05 by taung             #+#    #+#             */
/*   Updated: 2024/10/24 02:27:43 by taung            ###   ########.fr       */
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
		if(!(num[i] >= '0' && num[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_limit(char *num)
{
	long	numb;

	numb = ft_atol((const char*)num);
	if (numb >= -2147483648 && numb <= 2147483647)
	{
		return (1);
	}
	return (0);
}

int	validation_helper(char **inputs, int (*validation_func)(char*))
{
	int	i;
	int	j;
	char	**numbers;

	i = 1;
	while (inputs[i])
	{
		numbers = ft_split(inputs[i], ' ');
		j = 0;
		while (numbers[j])
		{
			if(!(validation_func(numbers[j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_duplicate(char **inputs)
{
	int		i;

	i = 1;
	while (inputs[i])
	{
		if(!(duplicate_helper(inputs, i)))
			return (0);
		i++;
	}
	return (1);
}
/* change is_duplicate to this one!
char **collect_numbers(char **inputs)
{
    char **all_numbers = NULL;
    int i = 1;
    int total_count = 0;
    int len = 0;
    char **temp;

    // First loop: Count total number of elements
    while (inputs[i])
    {
        temp = ft_split(inputs[i], ' ');
        len += len_numbers(temp); // Count number of split parts
        free_inputs(temp); // Free temporary split result
        i++;
    }

    // Allocate memory for all_numbers array
    all_numbers = malloc(sizeof(char *) * (len + 1)); // +1 for NULL terminator
    if (!all_numbers)
        return NULL; // Check allocation success

    // Reset index for the second loop
    i = 1;

    // Second loop: Populate all_numbers with the actual numbers
    while (inputs[i])
    {
        temp = ft_split(inputs[i], ' ');
        for (int j = 0; temp[j]; j++) // Corrected the loop condition
        {
            all_numbers[total_count] = ft_strdup(temp[j]); // Copy each number
            total_count++;
        }
        free_inputs(temp); // Free temporary split result
        i++;
    }
    all_numbers[total_count] = NULL; // NULL terminate the array

    return all_numbers;
}


// Function to check for duplicates in the array of all numbers
int is_duplicate(char **inputs)
{
    char **all_numbers = collect_numbers(inputs);
    int i = 0, j = 0;

    while (all_numbers[i])
    {
        j = i + 1;
        while (all_numbers[j])
        {
            if (ft_atoi(all_numbers[i]) == ft_atoi(all_numbers[j]))
            {
                free_inputs(all_numbers);
                return 0; // Duplicate found
            }
            j++;
        }
        i++;
    }
    free_inputs(all_numbers);
    return 1; // No duplicates found
}*/

int	validation(char **inputs)
{
	if(!validation_helper(inputs, &is_number))
	{
		ft_putstr_fd("Error !number\n", 2);
		return (0);
	}
	if(!validation_helper(inputs, &is_limit))
	{
		ft_putstr_fd("Error limit over\n", 2);
		return (0);
	}
	if(!is_duplicate(inputs))
	{
		ft_putstr_fd("Error duplicate inputs\n", 2);
		return (0);
	}
	return (1);
}
