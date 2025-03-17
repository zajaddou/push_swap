
#include "push_swap.h"

void index_node(t_stack **stack_a)
{
    t_stack *temp;
    t_stack *min;
    int		i;

	i = 0;
    while (1)
    {
        temp = *stack_a;
        min = NULL;

        while (temp)
        {
            if (temp->index == -1)
            {
                if (min == NULL)
                    min = temp;
                else if (temp->data < min->data)
                    min = temp;
            }
            temp = temp->next;
        }
        if (min == NULL)
            break;
        min->index = i++;
    }
}

void print_node(t_stack *stack_a, int c)
{
	t_stack *temp = stack_a;

	if (temp)
        printf("\nStack %c :", c);
	while (temp)
	{
		printf("\n%d | %d ", temp->index , temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int stack_size(t_stack *stack)
{
    t_stack     *temp;
    unsigned int size;

    size = 0;
    temp = stack;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return (size);
}

void add_node(t_stack **real, int data)
{
    t_stack *temp;
    t_stack *new;

    if (stack_size(*real) == 0)
	{
        *real = ft_malloc(sizeof(t_stack));
        (*real)->data = data;
        (*real)->index = -1;
        (*real)->next = NULL;
    }
    else {
        temp = *real;
        new = ft_malloc(sizeof(t_stack));
        new->data = data;
        new->index = -1;
        new->next = NULL;

        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}
