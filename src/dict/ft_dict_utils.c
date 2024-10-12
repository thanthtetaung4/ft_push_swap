/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:51:18 by taung             #+#    #+#             */
/*   Updated: 2024/10/07 12:30:52 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../header/push_swap.h"

void	ft_make_dict(int *value, int *key, ft_dict *dict, size_t len)
{
	dict->keys = key;
	dict->values = value;
	dict->len = len;
}

void	ft_print_dict(ft_dict *dict)
{
	int	i;

	i = 0;
	while(i < dict->len)
	{
		printf("Key: %d => value: %d\n",dict->keys[i],dict->values[i]);
		i++;
	}
}

int	ft_find_value(ft_dict *dict, int key)
{
	for (size_t i = 0; i < dict->len; i++)
	{
		if (key == dict->keys[i])
			return dict->values[i];
	}
	return 0;
}

int main()
{
	int values[5] = {-3, 4, 2, 1, 5};
	int keys[5] = {0, 3, 2, 1, 4};

	//make dict test
	ft_dict *dict = malloc(sizeof(ft_dict));
	ft_make_dict(values,keys,dict,5);
	ft_print_dict(dict);

	//find dict test
	int key = 4;
	printf("key[%d] => %d\n",key,ft_find_value(dict, key));
}
