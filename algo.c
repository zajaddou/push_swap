
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

int get_index(t_stack **stack, int i)
{
    t_stack *tmp;
    int     pos;

    tmp = *stack;
    pos = 0;
    while (tmp)
    {
        if (tmp->index == i)
            break;
        tmp = tmp->next;
        pos++;
    }
    return (pos);
}

void sort_5(t_stack **stack_a, t_stack **stack_b, char c)
{
    int i = -1;

    while (++i < 2)
    {
        int pos = get_index(stack_a, i);

        if (pos == 1)
            rotate(stack_a, c);
        else if (pos == 2)
        {
            rotate(stack_a, c);
            rotate(stack_a, c);
        }
        else if (pos == 3)
        {
            reverse_rotate(stack_a, c);
            reverse_rotate(stack_a, c);
        }
        else if (pos == 4)
            reverse_rotate(stack_a, c);
        push(stack_a, stack_b);
    }
}


