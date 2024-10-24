/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:44:06 by taung             #+#    #+#             */
/*   Updated: 2024/10/24 18:47:05 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

t_numbers	init_numbers(char **inputs)
{
	t_numbers numbers;
	char **all_numbers;
	int i;

	i = 0;
	numbers.len = get_total_numbers(inputs);
	numbers.numbers = malloc(sizeof(int) * numbers.len);
	all_numbers = collect_numbers(inputs);
	while(all_numbers[i])
	{
		numbers.numbers[i] = ft_atoi(all_numbers[i]);
		i++;
	}
	free_inputs(all_numbers);
	return numbers;
}

t_list	*init_stack(t_numbers numbers)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 0;
	while (i < numbers.len)
	{
		ft_lstadd_front(&list, ft_lstnew(&numbers.numbers[i]));
		i++;
	}
	return (list);
}
