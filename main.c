
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
    int data;
    struct s_data *next;
} s_data;

void struct_print(struct s_data *ptr)
{
    while (ptr->next != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc, char const *argv[])
{
    s_data *tmp;
    s_data *head = malloc(sizeof(s_data));

    if (!head)
        return (1);
    
    int i = 0;

    tmp = head;
    while (i < 5)
    {
        tmp->data = i;
        tmp->next = malloc(sizeof(s_data));
        tmp = tmp->next;
        i++;
    }
    tmp->next = NULL;

    struct_print(head);
    
    return (0);
}
