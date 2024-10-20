/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:39:13 by taung             #+#    #+#             */
/*   Updated: 2024/10/07 12:40:45 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	ft_print_arr(int *arr, size_t len)
{
	size_t	i;

	i = 0;
	while(i < len)
	{
		printf("%d\t",arr[i]);
		i++;
	}
}