
#include "push_swap.h"

void sort_3(t_stack **stack, int size, char c)
{
	if ((*stack)->index == (size - 1))
		rotate(stack, c);
	else if ((*stack)->index < (*stack)->next->index)
		reverse_rotate(stack, c);
	if ((*stack)->index > (*stack)->next->index)
		swap(stack, c);
}
