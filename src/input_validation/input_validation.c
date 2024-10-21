/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:32:05 by taung             #+#    #+#             */
/*   Updated: 2024/10/21 22:38:53 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	validation_checks(char **numbs, char *numb, int i)
{
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
	if(!is_duplicate(numbs, numb, i))
	{
		ft_putstr_fd("Error duplicate\n", 2);
		return 0;
	}
	return (1);
}

// multi inputs validation
int	validation(char **inputs)
{
	int	i;

	i = 0;
	while (inputs[i])
	{
		if(!validation_checks(inputs, inputs[i], i))
			return (0);
		i++;
	}
	return (1);
}


