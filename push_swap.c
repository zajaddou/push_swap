
#include "push_swap.h"

void leak()
{
	system("leaks push_swap");
}

int main(int ac, char *av[])
{
	//atexit(leak);
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	int size = 0;
	parsing(ac, av, &size, &stack_a);

	index_node(&stack_a);

	if (size == 2 || size == 3)
		sort_2_3(&stack_a);
	else if (size == 4 || size == 5)
		sort_4_5(&stack_a, &stack_b);
	else if (size > 5)
		big_sort(&stack_a, &stack_b);
	else
		ft_exit("Cant sort");

	print_node(stack_a);
	print_node(stack_b);
}
