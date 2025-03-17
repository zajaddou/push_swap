
#include "push_swap.h"

static int	is_empty(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!((str[i] >= 9 && str[i] <= 13 ) || str[i] == ' '))
			return (0);
	return (1);
}

static int is_valid(char *str)
{
	if (is_empty(str))
		return (0);
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || (*str >= 9 && *str <= 13 ) || *str == ' ')
		{
			if (*str >= '0' && *str <= '9')
			{
				str++;
				if ((*str == '-' || *str == '+'))
					return (0);
			}
			else
				str++;
		}
		else if (*str == '-' || *str == '+')
		{
			str++;
			if (!(*str >= '0' && *str <= '9'))
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

static void check_args(char *av[])
{
	while (*(++av))
		if (!is_valid(*av))
			ft_exit("Invalid Args");
}

static int	count_word(char const *s)
{
	int	c_words;
	int	i;

	i = 0;
	c_words = 0;
	while (s[i])
	{
		if (!((s[i] >= 9 && s[i] <= 13 ) || s[i] == ' '))
		{
			c_words++;
			while (s[i] && !((s[i] >= 9 && s[i] <= 13 ) || s[i] == ' '))
				i++;
		}
		else
			i++;
	}
	return (c_words);
}

static char *combine_args(int ac, char **av)
{
	char	*input;
	char	*temp;
	int 	i;

	i = 0;
	input = NULL;
	while (++i < ac)
	{
		temp = input;
		input = ft_strjoin(input, av[i]);
		free(temp);
		if ((i+1) < ac)
		{
			temp = input;
			input = ft_strjoin(input, " ");
			free(temp);
		}
	}
	i = -1;
	while (input[++i])
		if ((input[i] >= 9 && input[i] <= 13 ))
			input[i] = ' ';
	if (is_empty(input))
		ft_exit("Empty String");
	return (input);
}

static int is_duplicate(int *list, int size)
{
    int		a;
	int		b;

    a = 0;
    while (a < size)
    {
        b = a + 1;
        while (b < size)
        {
            if (list[a] == list[b])
                return (1);
            b++;
        }
        a++;
    }
    return (0);
}

static int is_sorted(int *list, int size)
{
    int a = 0;

    while (a < (size - 1))
    {
        if (list[a] > list[a + 1])
            return (0);
        a++;
    }
    return (1);
}

static int *create_list(int size, char *input)
{
	int		*list;
	char	**split;
    int     i;
    
    i = 0;
    split = ft_malloc(sizeof(char *) * (size + 1));
	split = ft_split(input, ' ');
	split[size] = NULL;
	free(input);
	list = ft_malloc(sizeof(int) * size);
	i = -1;
	while (split[++i] != NULL)
		list[i] = extra_atoi(split[i]);
    i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
    return (list);
}

int *parsing(int ac, char **av, int *size)
{
	char	*input;
	int		*list;

	if (ac == 1)
		ft_exit(NULL);
	check_args(av);
	input = combine_args(ac, av);
	*size = count_word(input);
    list = create_list(*size, input);
	if (is_duplicate(list, *size))
		ft_exit("Duplicate input");
	if (is_sorted(list, *size))
		ft_exit(NULL);
	return (list); 
}
