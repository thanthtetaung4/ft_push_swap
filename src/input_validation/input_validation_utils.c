/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:32:28 by taung             #+#    #+#             */
/*   Updated: 2024/10/21 22:24:11 by taung            ###   ########.fr       */
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

int	is_duplicate(char **numbs, char *numb, int index)
{
	int	i;

	i = index + 1;
	while (numbs[i])
	{
		if (ft_atoi(numbs[i]) - ft_atoi(numb) == 0)
			return (0);
		i++;
	}
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
