
#include "push_swap.h"

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int range;

	i = 0;
	range = 18;
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
		}
		else
			rotate(stack_a);
	}
}
