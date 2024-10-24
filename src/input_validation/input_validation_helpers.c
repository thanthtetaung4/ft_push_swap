/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:56:21 by taung             #+#    #+#             */
/*   Updated: 2024/10/24 00:06:05 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	is_number_helper(char *num)
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

int	is_limit_helper(char *num)
{
	long	numb;

	numb = ft_atol((const char*)num);
	if (numb >= -2147483648 && numb <= 2147483647)
	{
		return (1);
	}
	return (0);
}
