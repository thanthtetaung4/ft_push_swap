/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tha <tha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 05:02:20 by taung             #+#    #+#             */
/*   Updated: 2024/10/28 00:29:13 by tha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	sort_two(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	if (*((int *)temp->content) > *((int *)temp->next->content))
		sa(stack_a);
}

void	sort_three(t_list **stack_a, t_list **stack_b)
{
	int	values[3];

	values[0] = *((int *)(*stack_a)->content);
	values[1] = *((int *)(*stack_a)->next->content);
	values[2] = *((int *)(*stack_a)->next->next->content);
	(void)stack_b;
	if (values[0] > values[2])
	{
		ra(stack_a);
		if (values[1] < values[0] && values[1] > values[2])
			sa(stack_a);
		else if (values[1] > values[0])
			ra(stack_a);
	}
	else
	{
		if (values[0] > values[1])
			sa(stack_a);
		else if (values[1] > values[2])
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	values[4];
	int	smallest;

	values[0] = *((int *)(*stack_a)->content);
	values[1] = *((int *)(*stack_a)->next->content);
	values[2] = *((int *)(*stack_a)->next->next->content);
	values[3] = *((int *)(*stack_a)->next->next->next->content);
	smallest = find_smallest(values, 4);
	sort_four_condition(stack_a, stack_b, values, smallest);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	values[5];
	int	smallest;

	values[0] = *((int *)(*stack_a)->content);
	values[1] = *((int *)(*stack_a)->next->content);
	values[2] = *((int *)(*stack_a)->next->next->content);
	values[3] = *((int *)(*stack_a)->next->next->next->content);
	values[4] = *((int *)(*stack_a)->next->next->next->next->content);
	smallest = find_smallest(values, 5);
	sort_condition_five(stack_a, stack_b, values, smallest);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int len)
{
	int	bits;
	int	i;
	int	j;

	bits = 0;
	i = 0;
	while ((len >> bits) != 0)
		bits++;
	while (i < bits)
	{
		j = 0;
		while (j < len)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
