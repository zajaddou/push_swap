/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:34:35 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 07:19:25 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "LIBFT/libft.h"

typedef struct stack
{
	int				data;
	int				index;
	char			place;
	struct stack	*next;
}	t_stack;

int		is_empty(char *str);
int		is_sorted(int *list, int size);
int		is_duplicate(int *list, int size);
int		is_valid(char *str);

void	ft_free(void *ptr);
void	ft_exit(char *why);
void	*ft_malloc(size_t size);
int		extra_atoi(const char *str);

void	putmove(char *str, char c);
void	parsing(int ac, char **av, int *size, t_stack **stack_a);

int		stack_size(t_stack *stack);
void	add_node(t_stack **real, int data);
void	index_node(t_stack **stack_a);

void	push(t_stack **src, t_stack **dest);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

void	sort_2_3(t_stack **stack);
void	sort_4_5(t_stack **stack_a, t_stack **stack_b);
void	big_sort(t_stack **stack_a, t_stack **stack_b, int range);

#endif
