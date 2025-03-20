
#include "push_swap.h"

static int small_index(t_stack *stack)
{
    t_stack *tmp;
    int		min_i;
	int		min_p;
    int		pos;

	pos = 0;
	min_p = 0;
	tmp = stack;
	min_i = tmp->index;
    while (tmp)
    {
        if (tmp->index < min_i)
        {
            min_i = tmp->index;
            min_p = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return min_p;
}

static void push_index(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;

	size = stack_size(*stack_a);
	if (size == 4 || size == 5)
	{
		pos = small_index(*stack_a);
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
	push_index(stack_a, stack_b);
	push_index(stack_a, stack_b);
	sort_2_3(stack_a, 'a');
	push(stack_b, stack_a, 'a');
	if (stack_size(*stack_b) == 1)
		push(stack_b, stack_a, 'a');
}
