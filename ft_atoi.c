/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:57:15 by zajaddou          #+#    #+#             */
/*   Updated: 2025/02/26 11:08:20 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	long	before;

	sign = 1;
	result = 0;
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || (*str == 32)))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		ft_exit(1);
	while (*str >= '0' && *str <= '9')
	{
		before = result;
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str)
		ft_exit(1);
	if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
			ft_exit(1);
	return ((result * sign));
}
