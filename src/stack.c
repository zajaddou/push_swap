/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:30:14 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 08:28:54 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_node(t_stack **stack_a)
{
	t_stack			*temp;
	t_stack			*min;
	unsigned int	i;

	i = 0;
	while (1)
	{
		temp = *stack_a;
		min = NULL;
		while (temp)
		{
			if (temp->index == -1)
			{
				if (min == NULL)
					min = temp;
				else if (temp->data < min->data)
					min = temp;
			}
			temp = temp->next;
		}
		if (min == NULL)
			break ;
		min->index = i++;
	}
}

int	stack_size(t_stack *stack)
{
	t_stack			*temp;
	unsigned int	size;

	size = 0;
	temp = stack;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

void	add_node(t_stack **real, int data)
{
	t_stack	*temp;
	t_stack	*new;

	if (stack_size(*real) == 0)
	{
		*real = ft_malloc(sizeof(t_stack));
		(*real)->data = data;
		(*real)->place = 'a';
		(*real)->index = -1;
		(*real)->next = NULL;
	}
	else
	{
		temp = *real;
		new = ft_malloc(sizeof(t_stack));
		new->data = data;
		new->place = 'a';
		new->index = -1;
		new->next = NULL;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
