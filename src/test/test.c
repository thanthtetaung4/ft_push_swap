#include "../../header/push_swap.h"

int main(int argc, char **argv)
{
	t_list	*list;
	// t_list	*node1;
	// t_list	*node2;
	// t_list	*node3;

	list = NULL;
	/*
	// Create nodes
	node1 = ft_lstnew(ft_strdup("Hello")); // strdup() allocates memory and copies the string
    node2 = ft_lstnew(ft_strdup("World"));
    node3 = ft_lstnew(ft_strdup("42"));
	// Add nodes to the list
	ft_lstadd_front(&list, node1); // list = ["Hello"]
	ft_lstadd_front(&list, node2); // list = ["Hello", "World"]
	ft_lstadd_front(&list, node3); // list = ["Hello", "World", "42"]
	// Print list contents
	print_list(list); // Output: Hello World 42
	// Free the list
	ft_lstclear(&list, &free);
	*/

	t_numbers	numbers = init_numbers(argv);
	// int len = get_total_numbers(argv);
	// for (size_t i = 0; i < numbers.len; i++)
	// {
	// 	printf("%d\n",numbers.numbers[i]);
	// }

	list = init_stack(numbers);
	print_list(list);
	ft_lstclear(&list, &do_nth);
	free(numbers.numbers);
	return (0);
}
