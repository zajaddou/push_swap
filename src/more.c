/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:21:12 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 07:12:21 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(char *err)
{
	while (*err)
	{
		write(2, err, 1);
		err++;
	}
}

void	ft_exit(char *why)
{
	ft_free(NULL);
	if (why)
	{
		error("\033[1;31mError\033[0m\n");
		exit(1);
	}
	exit(0);
}

void	putmove(char *str, char c)
{
	while (*str)
		write(1, str++, 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
