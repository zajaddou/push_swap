
#include "push_swap.h"

static int max_index(t_stack **stack)
{
    t_stack *tmp;
    int     max;

    max = 0;
    tmp = *stack;
    while (tmp)
    {
        if (tmp->index > max)
            max = tmp->index;
        tmp = tmp->next;
    }
    return (max);
}

void sort_3(t_stack **stack, char c)
{
	if ((*stack)->index == max_index(stack))
		rotate(stack, c);
	if ((*stack)->index < (*stack)->next->index)
		reverse_rotate(stack, c);
	if ((*stack)->index > (*stack)->next->index)
		swap(stack, c);
}
