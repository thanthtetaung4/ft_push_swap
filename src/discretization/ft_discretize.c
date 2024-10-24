/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discretize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:31:44 by taung             #+#    #+#             */
/*   Updated: 2024/10/25 04:59:25 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void set_index(t_list **stack_a, int len)
{
	t_list *next;
	t_list *current_node;
	int index;
	int i;
	int j;

	i = 0;
	current_node = (*stack_a);
	while (i < len && current_node)
	{
		j = 0;
		index = 0;
		next = (*stack_a);
		while (j < len && next)
		{
			if (*((int *)(current_node->content)) > *((int *)(next->content)))
				index++;
			next = next->next;
			j++;
		}
		current_node->index = index;
		current_node = current_node->next;
		i++;
	}
}
