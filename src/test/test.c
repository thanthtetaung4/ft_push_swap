#include <stdio.h>

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

int	main()
{
	int	num = 1;
	int	*num_ptr = &num;
	t_list *head = ft_lstnew(num_ptr);
	printf("%p\n",num_ptr);
	printf("%d\n", *num_ptr);
	printf("%p\n",(head->content));
	printf("%d\n",*((int*)(head->content)));
}
