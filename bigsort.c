
#include "push_swap.h"

int	trap_detect(t_stack *stack)
{
	t_stack	*node;
	int		count;
	int		diff;

	count = 0;
	node = stack;
	while (node && node->next)
	{
		diff = ((node->index) - (node->next->index));
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		node = node->next;
	}
	if ((count * 10) >= (stack_size(stack) * 6))
		return (1);
	return (0);
}

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
		else if ((*stack_a)->index <= (i + range))
		{
			push(stack_a, stack_b);
			rotate(stack_b);
			i++;
		}
		else if (trap_detect(*stack_a))
			reverse_rotate(stack_a);
		else
			rotate(stack_a);
	}
}
