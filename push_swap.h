/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:23:18 by zajaddou          #+#    #+#             */
/*   Updated: 2025/02/26 10:49:10 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libc.h>

typedef struct  s_push
{
    int             data;
    int             index;
    int             cos_a;
    int             cos_b;
    int             position;
    struct s_push   *next;
}               t_push;

void    *ft_malloc(size_t size);
void    ft_exit(int flag);

#endif