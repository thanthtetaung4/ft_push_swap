/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:09:33 by taung             #+#    #+#             */
/*   Updated: 2024/10/20 22:07:11 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (validation_si(argv[1]))
		{
			//call init
			//call sort
		}
	}
	else if (argc > 2)
	{
		//do smth diff
	}
	else
		return (-1);

	return (0);
}
