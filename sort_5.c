
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

static void sort_b(t_stack **stack_a, t_stack **stack_b)
{
    (void)stack_a;
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap(stack_b, 'b');
    push(stack_b, stack_a, 'b');
    push(stack_b, stack_a, 'b');
}

void sort_5(t_stack **stack_a, t_stack **stack_b, char c)
{
    int pos;
    int i;

    i = -1;
    while (++i < 2)
    {
        pos = get_index(stack_a, i);
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
        push(stack_a, stack_b, 'a');
    }
    sort_3(stack_a, 'a');
    sort_b(stack_a, stack_b);
}
