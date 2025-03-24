/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:47:01 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 05:47:11 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(int *list, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (list[i] > list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(int *list, int size)
{
	int	a;
	int	b;

	a = 0;
	while (a < size)
	{
		b = a + 1;
		while (b < size)
		{
			if (list[a] == list[b])
				return (1);
			b++;
		}
		a++;
	}
	return (0);
}

int	is_empty(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ' )))
			return (0);
	return (1);
}
