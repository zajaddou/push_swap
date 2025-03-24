/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:21:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 05:23:37 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	printf("s%c\n", (*stack)->place);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;
	char	to;

	if (!src || !(*src))
		return ;
	if ((*src)->place == 'a')
		to = 'b';
	else
		to = 'a';
	printf("p%c\n", to);
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	temp->place = to;
	*dest = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
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
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	printf("rr%c\n", (*stack)->place);
	second_last = *stack;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
