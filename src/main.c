/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:09:33 by taung             #+#    #+#             */
/*   Updated: 2024/10/24 18:49:36 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_numbers	numbers;

	if (argc > 1)
	{
		if (validation(argv))
		{
			numbers = init_numbers(argv);
			stack_a = init_stack(numbers);
			print_list(stack_a);
			// //call sort
			ft_lstclear(&stack_a, &do_nth);
			free(numbers.numbers);
			printf("inputs OK :)\n");
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
