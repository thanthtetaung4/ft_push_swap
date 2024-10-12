/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:31:57 by taung             #+#    #+#             */
/*   Updated: 2024/06/06 18:26:32 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	small_str_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c && s[i-1] == c && s[i+1] != '\0')
			count++;
		i++;
	}
	if (s[ft_strlen(s) - 1] != c)
		count++;
	return (count);
}

void	put_substr(char **res, char *s, char c)
{
	int		i;
	int		j;
	char	*start;

	start = (char *) s;
	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			j = 0;
			res[i] = (char *)malloc((s - start) + 1 * sizeof(char));
			while (start < s)
			{
				res[i][j++] = *start++;
				printf("%p\n",&res[i][j]);
			}
			res[i][j] = '\0';
			printf("res[%i]: %s\n",i,res[i]);
			printf("res[0]: %s\n",res[0]);
			printf("res[0] addr:%p\n",&res[0][1]);
			i++;
			while(*start == c)
				start++;
			s = start;
		}
		s++;
	}

}

void	put_laststr(char **res, char *s, char c)
{
	int		i;
	size_t	j;
	char	*start;
	int		size;

	size = 0;
	i = small_str_count(s, c) - 1;
	start = s + (int)ft_strlen(s) - 1;
	while (start >= s && *start != c)
	{
		size++;
		start--;
	}
	start++;
	res[i] = (char *)malloc((size + 1) * sizeof(char));
	j = 0;
	while (*start && *start != c)
		res[i][j++] = *start++;
	res[i][j] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;
	int		i;

	word_count = small_str_count(s, c);
	res = malloc(word_count + 1 * sizeof(char));
	if (!res)
		return (NULL);
	put_substr (res, (char *) s, c);
	i = 0;
	while(i <= word_count)
	{
		if(res[i] == NULL)
			free(res);
		i++;
	}
	if (s[ft_strlen(s)-1] != c)
		put_laststr (res, (char *) s, c);
	res[word_count] = NULL;
	return (res);
}
int	main()
{
	char str[] = "split  ||this|for|me|||||!|";
	char  **res = ft_split(str,'|');
	int res_len = small_str_count(str,'|');
	printf("res_len: %i\n'%s' splitted into \n",res_len,str);
	for (int i = 0; i < res_len; i++)
	{
		printf("%s\n",res[i]);
	}
	// printf("%s\n",res[0]);
}
