
#include "push_swap.h"

static void swap_int(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void selection_sort(int *list, int size)
{
	int a;
	int b;

	a = 0;
	while (a < size)
	{
		b = (a + 1);
		while (b < size)
		{
			if (list[a] > list[b])
				swap_int(&list[a], &list[b]);
			b++;
		}
		a++;
	}
}

static int	*stack_to_list(t_stack *stack, int size)
{
	t_stack	*node;
	int		*list;
	int		i;

	node = stack;
	list = ft_malloc(sizeof(int) * size);
	i = 0;
	while (node->next != NULL)
	{
		list[i++] = node->data;
		node = node->next;
	}
	list[i] = node->data;

	selection_sort(list, size);

	return (list);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	*list;
	int	i;
	(void)stack_b;

	size = stack_size(*stack_a);
	list = stack_to_list(*stack_a, size);

	i = -1;
	while (++i < size)
		printf("%d ", list[i]);
}
