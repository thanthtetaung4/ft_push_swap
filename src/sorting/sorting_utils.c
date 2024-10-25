/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:34:02 by taung             #+#    #+#             */
/*   Updated: 2024/10/25 20:05:20 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	sorting_five_helper(t_list **stack_a, t_list **stack_b)
{
	sorting(stack_a, stack_b, sort_four);
	pa(stack_a, stack_b);
}

void	sort_condition_five(t_list **stack_a, t_list **stack_b,
	int *values, int smallest)
{
	if (smallest == values[0])
		sorting_five_helper(stack_a, stack_b);
	else if (smallest == values[1])
	{
		sa(stack_a);
		sorting_five_helper(stack_a, stack_b);
	}
	else if (smallest == values[2])
	{
		ra(stack_a);
		ra(stack_a);
		sorting_five_helper(stack_a, stack_b);
	}
	else if (smallest == values[3])
	{
		rra(stack_a);
		rra(stack_a);
		sorting_five_helper(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		sorting_five_helper(stack_a, stack_b);
	}
}
