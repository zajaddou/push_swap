/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 07:25:43 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/20 07:26:22 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **stack_a, t_stack **stack_b, int range)
{
	int	i;

	i = 0;
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
