
#include "push_swap.h"

void leak()
{
	system("leaks push_swap");
}

int main(int ac, char *av[])
{
	//atexit(leak);
	t_stack *stack_a = NULL;

	int size = 0;
	parsing(ac, av, &size, &stack_a);

	index_node(&stack_a);
	print_node(stack_a, 'A');

	reverse(&stack_a);

	print_node(stack_a, 'A');
}


// If the index of the first element equals the maximum index, perform a RA: move the first element to the last position..