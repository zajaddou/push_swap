
#include "push_swap.h"

void	big_sort(t_stack **stack_a, t_stack **stack_b, int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			push(stack_a, stack_b);
			rotate(stack_b);
			i++;
		}
		else
			rotate(stack_a);
	}
}
