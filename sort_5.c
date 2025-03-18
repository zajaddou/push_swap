
#include "push_swap.h"

static int get_index(t_stack **stack, int i)
{
    t_stack *tmp;
    int     pos;

    pos = 0;
    tmp = *stack;
    while (tmp && (tmp->index != i))
    {
        tmp = tmp->next;
        pos++;
    }
    return (pos);
}

static void act(t_stack **stack_a, t_stack **stack_b, int i)
{
    int pos;

    pos = get_index(stack_a, i);
    if (pos == 1)
        rotate(stack_a, 'a');
    else if (pos == 2)
    {
        rotate(stack_a, 'a');
        rotate(stack_a, 'a');
    }
    else if (pos == 3)
    {
        reverse_rotate(stack_a, 'a');
        if (i == 0)
            reverse_rotate(stack_a, 'a');
    }
    else if (pos == 4)
        reverse_rotate(stack_a, 'a');
    push(stack_a, stack_b, 'b');
}

void sort_5(t_stack **stack_a, t_stack **stack_b)
{
    act(stack_a, stack_b, 0);
    act(stack_a, stack_b, 1);
    
    sort_3(stack_a, 'a');
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap(stack_b, 'b');
    push(stack_b, stack_a, 'a');
    push(stack_b, stack_a, 'a');
}
