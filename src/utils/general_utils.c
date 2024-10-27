/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:57:58 by taung             #+#    #+#             */
/*   Updated: 2024/10/27 18:07:55 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

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

void	print_list(t_list *list)
{
	while (list)
	{
		ft_putstr_fd("value: ", 1);
		ft_putnbr_fd(*((int *)list->content), 1);
		ft_putstr_fd(", index: ", 1);
		ft_putnbr_fd(list->index, 1);
		ft_putchar_fd('\n', 1);
		list = list->next;
	}
}

void	do_nth(void *tlist)
{
	if (tlist || !tlist)
		return ;
	return ;
}
