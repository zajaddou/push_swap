/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:20:23 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 06:40:34 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	more_atoi(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	extra_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (*str && ((*str >= 9 && *str <= 13) || (*str == 32)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (more_atoi(sign));
		result = (result * 10) + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			ft_exit("Out of range");
		i++;
	}
	return (result * sign);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_exit("Failed to Allocate");
	ft_free(ptr);
	return (ptr);
}

void	ft_free(void *ptr)
{
	static void	*total[INT_MAX];
	static int	in;
	int			out;

	out = 0;
	if (!ptr)
		while (total[out])
			free(total[out++]);
	else
		total[++in] = ptr;
}
