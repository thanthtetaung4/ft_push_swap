#include <stdio.h>

#include "../../header/push_swap.h"

int	test_duplicate_helper(char **inputs, char *numb, int index_i, int index_j)
{
	int		i;
	int		j;
	char**	numbers;

	i = index_i;
	while (inputs[i])
	{
		j = 0;
		numbers = ft_split((const char*)inputs[i], ' ');
		if (len_numbers(numbers) > 1)
			j = index_j + 1;
		while (numbers[j])
		{
			printf("inside is_duplicate numb: %s \t & j: %d\n",numbers[j],j);
			if(ft_atoi(numbers[j]) - ft_atoi(numb) == 0)
				return (0);
			j++;
		}
		free_inputs(numbers);
		numbers = NULL;
		i++;
	}
	printf("%s \t is validated\n",numb);
	return (1);
}

int	test_is_duplicate(char **inputs)
{
	int	i;
	int	j;
	char **numbers;

	i = 1;
	while(inputs[i])
	{
		j = 0;
		numbers = ft_split((const char*)inputs, ' ');
		while (numbers[j])
		{
			if (!(test_duplicate_helper(inputs,numbers[j],i,j)))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	main(int argc, char **argv)
{
	if(test_is_duplicate(argv))
		printf("NO DUPLI\n");
	else
		printf("DUPLICATES\n");

}
