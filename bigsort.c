#include "push_swap.h"

void big_sort(t_stack **stack_a, t_stack **stack_b, int range)
{
    int i = 0;
    
    while (*stack_a)
    {
        if ((*stack_a)->index <= i) 
        {
            push(stack_a, stack_b, 'b');
            i++;
        }
        else if ((*stack_a)->index <= i + range) 
        {
            push(stack_a, stack_b, 'b');
            rotate(stack_b, 'b');
        }
        else 
            rotate(stack_a, 'a');
    }
}