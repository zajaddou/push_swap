/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:20:14 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 08:26:08 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	trap_detect(t_stack *stack)
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

static	int	max_nbr(t_stack *stack)
{
	t_stack	*node;
	int		max;

	node = stack;
	max = node->data;
	while (node)
	{
		if (node->data > max)
			max = node->data;
		node = node->next;
	}
	return (max);
}

int	max_place(t_stack *stack)
{
	t_stack	*node;
	int		i;
	int		max;

	i = 0;
	node = stack;
	max = max_nbr(node);
	while (node)
	{
		if (node->data == max)
			return (i);
		i++;
		node = node->next;
	}
	return (i);
}

void	sort_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		size;
	int		deep;
		
	node = *stack_b;

	size = stack_size(*stack_b)-1;
	
	while (stack_size(*stack_b) > 0)
	{
 		deep = max_place(*stack_b);
		if (deep == 0)
		{
			push(stack_b, stack_a);
			size--;
		}
		else if (deep <= size / 2)
			rotate(stack_b);
		else if (deep > size / 2)
			reverse_rotate(stack_b);
	}
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
	sort_b(stack_a, stack_b);
}
