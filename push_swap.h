
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "LIBFT/libft.h"

#define print_moves 1

#ifndef PUSH_SWAP
#define PUSH_SWAP

typedef struct stack
{
	char	place;
	int		data;
	int		index;
	struct stack *next;
} t_stack;

void     ft_free(void *ptr);
void     *ft_malloc(size_t size);
void     ft_exit(char *why);
int      extra_atoi(const char *str);
void     parsing(int ac, char **av, int *size, t_stack **stack_a);

int      stack_size(t_stack *stack);
void     add_node(t_stack **real, int data);
void     index_node(t_stack **stack_a);
void     print_stack(t_stack *stack_a);

void     push(t_stack **src, t_stack **dest);
void     swap(t_stack **stack);
void     rotate(t_stack **stack);
void     reverse_rotate(t_stack **stack);

void     sort_2_3(t_stack **stack);
void     sort_4_5(t_stack **stack_a, t_stack **stack_b);
void	 big_sort(t_stack **stack_a, t_stack **stack_b, int range);

#endif