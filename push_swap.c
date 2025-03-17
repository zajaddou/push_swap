
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

	if (size == 3)
		sort_3(&stack_a, 'a');
	else if (size == 5)
		sort_5(&stack_a, &stack_b, 'a');
	else
		ft_exit("Cant sort");
	print_node(stack_a, 'A');
	print_node(stack_b, 'B');
}
