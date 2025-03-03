/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:34:48 by zajaddou          #+#    #+#             */
/*   Updated: 2025/02/26 11:05:27 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free(void *ptr, int flag)
{
    static  void *total[INT_MAX];
    static  int i;
    int j;

    if (flag)
    {
        j = 0;
        while (total[j])
        {
            free(total[j]);
            j++;
        }
    }
    else
        total[++i] = ptr;
}

void    ft_exit(int flag)
{
    if (flag)
    {
        write(2, "Error\n", 7);
        ft_free(NULL, flag);
    }
    exit(flag);
}

void    *ft_malloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (!ptr)
        ft_exit(1);
    ft_free(ptr, 0);
    return (ptr);
}
