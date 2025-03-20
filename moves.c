
#include "push_swap.h"

// sa : swap a - swap the first 2 elements at the top of stack a.
// pa : push a - take the first element at the top of b and put it at the top of a.

void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	if (print_moves)
		printf("s%c\n", (*stack)->place);

	first = *stack;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack *temp;
	char 	to;

	if (!src || !(*src)) 
		return;
	if ((*src)->place == 'a')
		to = 'b';
	else
		to = 'a';
	if (print_moves)
		printf("p%c\n", to);
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	temp->place = to;
	*dest = temp;
}

void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	if (print_moves)
		printf("r%c\n", (*stack)->place);

	first = *stack;
	*stack = first->next;
	last = *stack;

	while (last->next)
		last = last->next;

	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack *last;
	t_stack *second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;

	if (print_moves)
		printf("rr%c\n", (*stack)->place);

	second_last = *stack;
	
	while (second_last->next->next)
		second_last = second_last->next;

	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
