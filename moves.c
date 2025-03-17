
#include "push_swap.h"

// sa : swap a - swap the first 2 elements at the top of stack a.
// pa : push a - take the first element at the top of b and put it at the top of a.

void swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    if (!stack || !(*stack) || !(*stack)->next)
        return;

    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

void push(t_stack **src, t_stack **dest)
{
    t_stack *temp;

    if (!src || !(*src)) 
        return;

    temp = *src;
    *src = (*src)->next;

    temp->next = *dest;
    *dest = temp;
}