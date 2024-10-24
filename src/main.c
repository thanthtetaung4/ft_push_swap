/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:09:33 by taung             #+#    #+#             */
/*   Updated: 2024/10/25 05:01:12 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_numbers	numbers;

	stack_b = NULL;
	if (argc > 1)
	{
		if (validation(argv))
		{
			numbers = init_numbers(argv);
			stack_a = init_stack(numbers);
			sort(&stack_a, &stack_b, numbers);
			ft_lstclear(&stack_a, &do_nth);
			free(numbers.numbers);
		}
	}
	else
		return (-1);
}
/*
./push_swap "1 2 3 4"5
===argc : 2===
===./push_swap===
===1 2 3 45===
!!! Since this is how CLI treats input I cannot fuck with it !!!
printf("===argc : %d===\n",argc);
	for (size_t i = 0; argv[i]; i++)
	{
		printf("===%s===\n",argv[i]);
	}
*/
