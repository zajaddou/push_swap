
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
		sort_3(&stack_a, size, 'a');
	if (size == 5)
		sort_5(&stack_a, &stack_b, 'a');
		
	print_node(stack_a, 'A');
	print_node(stack_b, 'B');
}

// If the first element isn’t the largest,
// check if the second element is. Compare their index. 
