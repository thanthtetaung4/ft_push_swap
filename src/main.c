/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:09:33 by taung             #+#    #+#             */
/*   Updated: 2024/10/24 14:49:28 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (validation(argv))
		{
			//call init
			//call sort
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
