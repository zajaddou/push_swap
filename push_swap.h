
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "LIBFT/libft.h"

#ifndef PUSH_SWAP
#define PUSH_SWAP

typedef struct stack
{
   int    data;
   int    index;
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
void     print_node(t_stack *stack_a, int c);

void     push(t_stack **src, t_stack **dest);
void     swap(t_stack **stack);
void     rotate(t_stack **stack);
void     reverse(t_stack **stack);

#endif