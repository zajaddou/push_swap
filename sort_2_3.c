
#include "push_swap.h"

void sort_2_3(t_stack **stack)
{
	int		n1;
	int		n2;
	int		n3;

	if (stack_size(*stack) == 3)
	{
		n1 = (*stack)->index;
		n2 = (*stack)->next->index;
		n3 = (*stack)->next->next->index;

		if (n1 > n2 && n1 > n3)
			rotate(stack);
		else if (n2 > n1 && n2 > n3)
			reverse_rotate(stack);
	}
	if ((*stack)->index > (*stack)->next->index)
		swap(stack);
}
