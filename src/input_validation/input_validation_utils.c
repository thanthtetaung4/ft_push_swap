/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:32:28 by taung             #+#    #+#             */
/*   Updated: 2024/10/22 21:35:23 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	r;
	char	sign;

	i = 0;
	r = 0;
	sign = '+';
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = '-';
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + nptr[i] - '0';
		i++;
	}
	if (sign == '-')
		r = r * -1;
	return (r);
}

int	is_limit(char *str)
{
	long	numb;

	numb = ft_atol((const char*)str);
	if (numb >= -2147483648 && numb <= 2147483647)
	{
		return (1);
	}
	return (0);
}

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

int	is_duplicate(char **inputs, char *numb, int index_i, int index_j)
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
