
#include "push_swap.h"

// sa : swap a - swap the first 2 elements at the top of stack a.
// pa : push a - take the first element at the top of b and put it at the top of a.

void swap(t_stack **stack, char c)
{
    t_stack *first;
    t_stack *second;

    printf("s%c\n", c);

    if (!stack || !(*stack) || !(*stack)->next)
        return;

    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

void push(t_stack **src, t_stack **dest, char c)
{
    t_stack *temp;

    if (!src || !(*src)) 
        return;

    temp = *src;
    *src = (*src)->next;

    temp->next = *dest;
    *dest = temp;
    printf("p%c\n", c);
}

void rotate(t_stack **stack, char c)
{
    t_stack *first;
    t_stack *last;

    printf("r%c\n", c);

    if (!stack || !(*stack) || !(*stack)->next)
        return;

    first = *stack;
    *stack = first->next;
    last = *stack;

    while (last->next)
        last = last->next;

    last->next = first;
    first->next = NULL;
}

void reverse_rotate(t_stack **stack, char c)
{
    t_stack *last;
    t_stack *second_last;

    printf("rr%c\n", c);

    if (!stack || !(*stack) || !(*stack)->next)
        return ;

    second_last = *stack;
    
    while (second_last->next->next)
        second_last = second_last->next;

    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}
