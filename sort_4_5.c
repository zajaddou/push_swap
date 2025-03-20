
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

static void push_index(t_stack **stack_a, t_stack **stack_b, int i)
{
    int pos;
    int size;

    size = stack_size(*stack_a);
    if (size == 4 || size == 5)
    {
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
            if (size == 5)
                reverse_rotate(stack_a, 'a');
        }
        else if (pos == 4)
            reverse_rotate(stack_a, 'a');
        push(stack_a, stack_b, 'b');
    }
}

void sort_4_5(t_stack **stack_a, t_stack **stack_b)
{
    push_index(stack_a, stack_b, 0);
    push_index(stack_a, stack_b, 1);
    sort_3(stack_a, 'a');
    push(stack_b, stack_a, 'a');
    if (stack_size(*stack_b) == 1)
        push(stack_b, stack_a, 'a');
}
