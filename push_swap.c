/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:33:20 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 06:06:48 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	parsing(ac, av, &size, &stack_a);
	index_node(&stack_a);
	if (size == 2 || size == 3)
		sort_2_3(&stack_a);
	else if (size == 4 || size == 5)
		sort_4_5(&stack_a, &stack_b);
	else if (size <= 100)
		big_sort(&stack_a, &stack_b, 16);
	else if (size > 100)
		big_sort(&stack_a, &stack_b, 32);
}
