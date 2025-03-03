#include "LIBFT/libft.h"
#include "push_swap.h"

void struct_print(t_push *ptr)
{
    while (ptr->next != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void    multi_args(char *av[], t_push **ptr, int i)
{
    printf("multi args : \n");
    t_push  *tmp;

    tmp = *ptr;
    while (av[i])
    {
        tmp->data = ft_atoi(av[i]);
        printf("%d\n", ft_atoi(av[i]));
        i++;
    }
}

void    one_arg(char *arg, t_push **ptr)
{
    printf("one_arg : \n");
    t_push  *tmp;
    int     i;
    char    **list;

    i = 0;
    tmp = *ptr;
    list = ft_split(arg, ' ');

    while (list[i] != NULL)
    {
        tmp->data = ft_atoi(list[i]);
        printf("%d\n", ft_atoi(list[i]));
        i++;
    }
}

int main(int ac, char *av[])
{
    t_push  *ptr;

    ptr = ft_malloc(sizeof(t_push));
    if (ac < 2)
        return (0);
    if (ac > 2)
        multi_args(av, &ptr, 1);
    else if (ac == 2)
        one_arg(av[1], &ptr);

    
    return (0);
}