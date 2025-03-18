
#include "push_swap.h"

void sort_3(t_stack **stack, char c)
{
    int n1 = (*stack)->index;
    int n2 = (*stack)->next->index;
    int n3 = (*stack)->next->next->index;

    if (n1 > n2 && n1 > n3)
        rotate(stack, c);
    else if (n2 > n1 && n2 > n3)
        reverse_rotate(stack, c);
    if ((*stack)->index > (*stack)->next->index)
        swap(stack, c);
}
