
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
	int i	= -1;

	int *list = parsing(ac, av, &size);
	
	while (++i < size)
		add_node(&stack_a, list[i]);

	index_node(&stack_a);

	push(&stack_a, &stack_b);
	print_node(stack_a, 'A');
	printf("\n");
	print_node(stack_b, 'B');
}
