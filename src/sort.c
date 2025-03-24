/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:28:25 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 05:30:07 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2_3(t_stack **stack)
{
	int	n1;
	int	n2;
	int	n3;

	if (stack_size(*stack) == 3)
	{
		n1 = (*stack)->index;
		n2 = (*stack)->next->index;
		n3 = (*stack)->next->next->index;
		if ((n1 > n2) && (n1 > n3))
			rotate(stack);
		else if ((n2 > n1) && (n2 > n3))
			reverse_rotate(stack);
	}
	if ((*stack)->index > (*stack)->next->index)
		swap(stack);
}

static int	small_index(t_stack *stack)
{
	t_stack	*node;
	int		min_i;
	int		min_p;
	int		pos;

	pos = 0;
	min_p = 0;
	node = stack;
	min_i = node->index;
	while (node)
	{
		if (node->index < min_i)
		{
			min_i = node->index;
			min_p = pos;
		}
		node = node->next;
		pos++;
	}
	return (min_p);
}

static void	push_small(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;

	size = stack_size(*stack_a);
	if (size == 4 || size == 5)
	{
		pos = small_index(*stack_a);
		if (pos == 1)
			rotate(stack_a);
		else if (pos == 2)
		{
			rotate(stack_a);
			rotate(stack_a);
		}
		else if (pos == 3)
		{
			reverse_rotate(stack_a);
			if (size == 5)
				reverse_rotate(stack_a);
		}
		else if (pos == 4)
			reverse_rotate(stack_a);
		push(stack_a, stack_b);
	}
}

void	sort_4_5(t_stack **stack_a, t_stack **stack_b)
{
	push_small(stack_a, stack_b);
	push_small(stack_a, stack_b);
	sort_2_3(stack_a);
	push(stack_b, stack_a);
	if (stack_size(*stack_b) != 0)
		push(stack_b, stack_a);
}
