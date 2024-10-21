/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:09:33 by taung             #+#    #+#             */
/*   Updated: 2024/10/21 22:41:43 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	single_str_ops(char *inputs)
{
	char **numbs;

	numbs = ft_split(inputs, ' ');
	if (validation(numbs))
	{
		//call init
		//call sort
		printf("inputs OK :)");
	}
	free_inputs(numbs);
}

void	multi_str_ops(char **inputs)
{
	if (validation(inputs))
	{
		//call init
		//call sort
		printf("inputs OK :)\n");
	}
}

int	main(int argc, char *argv[])
{

	if (argc == 2)
		single_str_ops(argv[1]);
	else if (argc > 2)
		multi_str_ops(argv);
	else
		return (-1);

	return (0);
}
