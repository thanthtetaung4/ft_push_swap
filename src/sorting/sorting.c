/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:34:09 by taung             #+#    #+#             */
/*   Updated: 2024/10/25 05:28:39 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b, t_numbers numbers)
{
	if (numbers.len > 1)
	{
		if (numbers.len == 2)
			sort_two(stack_a);
		else if (numbers.len == 3)
			sort_three(stack_a, stack_b);
		else if (numbers.len == 4)
			sort_four(stack_a, stack_b);
		else if (numbers.len == 5)
			sort_five(stack_a, stack_b);
		else
		{
			radix_sort(stack_a, stack_b,numbers.len);
		}
	}
}
