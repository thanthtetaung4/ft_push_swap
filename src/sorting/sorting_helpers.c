/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:46:30 by taung             #+#    #+#             */
/*   Updated: 2024/10/25 19:58:11 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	find_smallest(int *values, int len)
{
	int	smallest;
	int	i;

	i = 0;
	smallest = values[0];
	while (i < len)
	{
		if (values[i] < smallest)
			smallest = values[i];
		i++;
	}
	return (smallest);
}

void	sorting(t_list **stack_a, t_list **stack_b,
	void (f)(t_list **, t_list **))
{
	pb(stack_a, stack_b);
	f(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_four_condition(t_list **stack_a, t_list **stack_b,
	int *values, int smallest)
{
	if (smallest == values[0])
		sorting(stack_a, stack_b, sort_three);
	else if (smallest == values[1])
	{
		sa(stack_a);
		sorting(stack_a, stack_b, sort_three);
	}
	else if (smallest == values[2])
	{
		ra(stack_a);
		ra(stack_a);
		sorting(stack_a, stack_b, sort_three);
	}
	else
	{
		rra(stack_a);
		sorting(stack_a, stack_b, sort_three);
	}
}
