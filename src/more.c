/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:21:12 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 07:11:00 by zajaddou         ###   ########.fr       */
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

int	count_word(char const *s)
{
	int	c_words;
	int	i;

	i = 0;
	c_words = 0;
	while (s[i])
	{
		if (!((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
		{
			c_words++;
			while (s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
				i++;
		}
		else
			i++;
	}
	return (c_words);
}

void	putmove(char *str, char c)
{
	while (*str)
		write(1, str++, 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
